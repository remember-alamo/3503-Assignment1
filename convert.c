#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

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

    int power_result = 0; // used to determine which power to count down from.
    int multiplier = 1; // will be changed throughout the loop to store into the buffer.
    int power_max = 0; // power to count down from;

    for(int i = 0; power_result <= n; i++)
    {
        power_result = pow(base, i);
        if(power_result >= n)
        {
            power_max = i-1; //since the result is greater than n, subtract 1 from i to get the smaller number
        }
    }
    
    while (n > 0)
    {
        //getting the number to multiply the base^power by, and to store into the buffer
        int quotient = n / pow(base, power_max);
        
        if (quotient < 10)
        { 
            temp[pos++] = '0' + quotient; 
        }
        else
        { 
            temp[pos++] = 'A' + (quotient - 10); 
        }
        
        // subtraction process, b^i * q 
        n = n - (pow(base, power_max--) * quotient); 
    }

    temp[pos++] = '\0';
    int length = pos;

    char result[length];
    for(int i = 0; i <= length; i++)
    {
        result[i] = temp[i];
    }
    result[length-1] = '\0';
    strncpy(out, result, pos);
}

void print_tables ( uint32_t n ) 
{
    char bin [33] , oct [12] , hex [9];

    // Original number
    div_convert (n , 2 , bin ) ;
    div_convert (n , 8 , oct ) ;
    div_convert (n , 16 , hex ) ;
    printf ("Original : Binary = %s Octal = %s Decimal = %u Hex = %s\n", bin, oct, n,hex);

    // Left shift by 3
    uint32_t shifted = n << 3;
    div_convert ( shifted , 2 , bin ) ;
    div_convert ( shifted , 8 , oct ) ;
    div_convert ( shifted , 16 , hex ) ;
    printf ("Left Shift by 3: Binary =%s Octal =%s Decimal =%u Hex =%s\n", bin, oct, shifted, hex);

    // AND with 0 xFF
    uint32_t masked = n & 0xFF ;
    div_convert ( masked, 2, bin );
    div_convert ( masked, 8, oct );
    div_convert ( masked, 16, hex );
    printf ( "AND with 0xFF: Binary=%s Octal=%s Decimal =%u Hex =%s\n", bin, oct, shifted, hex);
}