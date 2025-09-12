#include <stdio.h>
#include <string.h>
#include <stdint.h>

void div_convert(uint32_t n, int base, char *out);

int main(void)
{
    char buffer[65];

    div_convert(255, 16, &buffer);
    printf("result: %s\n", buffer);

    FILE *file = fopen("test_section.txt", "r");
    if (file == NULL)
    {
        printf("Error: Could not open file\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        //process lines here
        line[strcspn(line, "\n")] = '\0';
        printf("Line: %s\n", line);

        char temp[65];                                              // throwing characters into buffer to compare parts of the line
        
        char method_use[16];                                        // to be filled when the method to be tested is found
        char num_1[16];                                             // decimal number to convert
        char base_to[16];                                           // base to convert to
        char expected[32];                                          // expected output to compare to

        int pos1, pos2, pos3;
        for (int i = 0; i <= sizeof(line); i++)
        {
            // getting the function type by combing through the char array and stopping until we get a space.
            // otherwise, continue adding characters to the buffer.
            if(line[i] == ' ')
            {
                // turning the space into null terminator for string storage.
                temp[i] = '\0';
                // converting our buffer into a string
            }
            temp[i] = line[i];
            
        }
    }
    fclose(file);

    return 0;
}