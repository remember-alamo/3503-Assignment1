#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

//methods that we're gonna use
void div_convert(uint32_t n, int base, char *out);
void sub_convert(uint32_t n, int base, char *out);
void print_tables ( uint32_t n );

int main(void)
{
    int tests = 0;
    int pass = 0;
    char buffer[65];

    FILE *file = fopen("a1_test_file.txt", "r");
    if (file == NULL)
    {
        printf("Error: Could not open file\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        //ignoring newlines and comments
        if(line[0] == '\0'){ continue; }
        if(line[0] == '#') { continue; }

        char hold = '\0';
        char temp[32];

        int pos = 0;
        while (hold != ' ')
        {
            temp[pos] = line[pos];
            pos++;
            hold = line[pos];
        }
        temp[pos] = '\0';

        char str1[pos];

        strcpy(str1, temp);

        int space_method = pos+1;
        if( (strcmp(str1, "div_convert") == 0) || (strcmp(str1, "sub_convert") == 0) ) //both have similar formats... good check.
        {
            int dec = 0;
            int base = 0;

            int space_dec = 0;
            int space_base = 0;
            //grabbing first space after the method space location
            hold = '\0';
            while(hold != ' '){
                pos++;
                hold = line[pos];
            }
            space_dec = pos+1;
            //grabbing second space after the second param space location.
            hold = '\0';
            while(hold != ' '){
                pos++;
                hold = line[pos];
            }
            space_base = pos+1;
            //finding the end of the line position
            hold = '.';
            while(hold != '\0'){
                pos++;
                hold = line[pos];
            }

            // string of decimal input before conversion to int
            char dec_ch[(space_dec - 1 ) - space_method + 1];
            // string of base input before conversion to int
            char base_ch[(space_base) - space_dec - 1];
            // string of expected output
            char exp_output [pos - space_base + 1];

            //filling up the characters from the line, variable by variable. space by space...
            // the positions were saved in an earlier loop of the line, here, the inputs to the method
            // will be filled by going through the lines one more time.
            for(int i = 0; i <= sizeof(dec_ch) - 1; i++)
            {
                dec_ch[i] = line[space_method + i];
            }
            dec_ch[sizeof(dec_ch)-1] = '\0';

            for(int i = 0; i <= sizeof(base_ch) - 1; i++)
            {
                base_ch[i] = line[space_dec + i];
            }
            base_ch[sizeof(dec_ch)-1] = '\0';

            for(int i = 0; i <= sizeof(exp_output) - 1; i++)
            {
                exp_output[i] = line [space_base + i];
            }
            exp_output[sizeof(exp_output)-1] = '\0';

            dec = atoi(dec_ch);
            base = atoi(base_ch);

            // since we are going to be using one of two methods with exactly the same parameters,
            // then we might as well use this approach.
            if(strcmp(str1, "div_convert") == 0)
            { div_convert(dec, base, &buffer); }
            else if (strcmp(str1, "sub_convert") == 0)
            { sub_convert(dec, base, &buffer); }

            if(strcmp(exp_output, buffer) == 0)
            {
                tests++;
                printf("Test %d: %s(%s, %s) -> Expected: \"%s\", got \"%s\" [PASS]\n", tests, str1, dec_ch, base_ch, exp_output, buffer);
                pass++;
            }
            else
            {
                tests++;
                printf("Test %d: %s(%s, %s) -> Expected: \"%s\", got \"%s\" [FAIL]\n", tests, str1, dec_ch, base_ch, exp_output, buffer);
            }
        }
        else if(strcmp(str1, "print_tables") == 0)
        {
            //finding the last space
            hold = '\0';
            char temp[32];

            int space_n = 0;

            //same process as the above
            while(hold != ' '){
                pos++;
                hold = line[pos];
            }
            space_n = pos+1;
            char n_ch[(space_n - 1 ) - space_method + 1];

            for(int i = 0; i <= sizeof(n_ch) - 1; i++)
            {
                n_ch[i] = line[space_method + i];
            }
            int num = atoi(n_ch);

            printf("Test %d: %s(%d) -> \n", tests, str1, num);
            print_tables (num);
            printf("[PASS]\n");
        }
        else
        {
            printf("the strings do not match!\n");
        }
    }
    fclose(file);

    return 0;
}