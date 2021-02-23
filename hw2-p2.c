#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Display the binary
void bin(unsigned n)
{
    printf("\t%u = ", n);
    for (unsigned i = 1 << 15; i > 0; i = i / 2){
        if (i == 128) {
            printf("\t");
        }
        (n & i) ? printf("1") : printf("0");
    }
    printf("\n");
}

// create the power2 function
int power2(int a, int b){

    printf("number: \n");
    bin(a);
    printf("pow: \n");
    bin(b);

    return a << b;

}

// main function
int main(){

    unsigned int a;
    unsigned int b;

    printf("Enter two integers: ");

    scanf("%u", &a);
    scanf("%u", &b);

    unsigned int res = power2(a, b);

    printf("%u * %d^%u = %u\n", a, 2, b, res);

    bin(res);
    
}