#include <stdint.h>

uint32_t number = 156;
char digit = '5';

char binary_string[33];
char hex_string[9];

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
        if (remainder < 0){ temp[pos++] = '0' + remainder; }
        else { temp[pos++] = 'A' + (remainder - 10); }
    }

    //REVERSE the result
    while (n > 0){
        /*
        1. get length of array
        2. set up new array
        3. pass in the results of the temp array, from bottom to top of the array
        4. go through array again, convert any digits over 9 to their respective hex letters
        5. pass array into *out
        6. win
        */
    }


    //TODO: figure it out dude

    //don't forget about hexadecimal. so. that's probably an if statement and!!! just so you don't forget it!
    //10: A
    //11: B
    //12: C
    //13: D
    //14: E
    //15: F
}

void sub_convert(uint32_t n, int base, char*out)
{
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

