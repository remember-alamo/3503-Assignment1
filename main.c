#include <stdio.h>
#include <stdint.h>

void div_convert(uint32_t n, int base, char *out);

int main(void)
{
    char buffer[65];

    div_convert(255, 16, &buffer);
    printf("result: %s\n", buffer);
    return 0;
}