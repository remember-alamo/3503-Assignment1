#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void div_convert(uint32_t n, int base, char *out);

int main(void)
{
    char buffer[65];

    FILE *file = fopen("test_section.txt", "r");
    if (file == NULL)
    {
        printf("Error: Could not open file\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

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
        if( (strcmp(str1, "div_convert") == 0) ) //
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
            div_convert(dec, base, &buffer);

            if(strcmp(exp_output, buffer) == 0)
            {
                printf("%s(%s, %s) -> Expected: \"%s\", got \"%s\" [PASS]\n", str1, dec_ch, base_ch, exp_output, buffer);
            }
        }
        else
        {
            printf("the strings do not match!\n");
        }
    }
    fclose(file);

    return 0;
}