#include <stdio.h>

int add(int a, int b){
    return a + b;
}

int main(void){
    int x = 3;
    int y = 7;
    int sum = add(x,y);

    printf("sum of %d and %d is %d\n", x, y, sum);
    return 0;
}