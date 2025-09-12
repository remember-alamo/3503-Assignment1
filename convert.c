#include <stdint.h>
#include <string.h>
#include <stdio.h>


void test(int *out)
{
    *out = *out + 5;
}


void div_convert(uint32_t n, int base, char *out){
    char temp[65];
    int pos = 0;

    //zero case
    if (n == 0){
        strcpy(out, "0");
        return;
    }
    // extract digits (perform division process, going through each position in the inputted digit (IMPORTANT....))
    // ... from LEFT to RIGHT
    while (n > 0){
        int remainder = n % base;
        n = n / base;

        //convert digit to character
        if (remainder < 10)
        { 
            temp[pos++] = '0' + remainder; 
        }
        else
        { 
            temp[pos++] = 'A' + (remainder - 10); 
        }
    }

    //REVERSE the result
    temp[pos++] = '\0';
    int length = pos;
    
    //the position we got to IS the length of the array, might as well create one with this length.
    char result[length];

    /*
        fill the result array, the position we got to in the buffer is already there.
        thus... we subtract the position right away, because we don't wanna have the result
        start with a null terminator...!
    */

    pos -= 2;
    for(int i = 0; pos >= 0; i++)
    {
        result[i] = temp[pos];
        pos--;
    }
    result[length-1] = '\0';

    strncpy(out, result, length);
}

void sub_convert(uint32_t n, int base, char*out)
{
    char temp[65];
    int pos = 0;
    /*
    1. create array buffer
    2. begin doing math
        z. f is the decimal number
        a. start looping through p^n where p is the base, and n is the power position
        b. if p^n is too big, n-1
        c. if p^n is below f, multply it 
        d. if p^n * 2 is still too big, multiply by 3, or 4, keep going until it's too big again
        e. record the multiplier somewhere in the array buffer
    3. reverse the array
    4. pass the array buffer to *out
    5. win!
    */
}

