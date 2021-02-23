#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// binary to decimal function
int binToDecimal(char s[]) {
    int dec = 0;
    int i;

    for (i = 0; i < 16; i++) {
        dec <<= 1;
        dec += s[i] - '0';
    }

    return dec;
}

// reverse function
void reverse(unsigned int n) 
{ 
    char binaryNum[20]; 
    printf("\t%u = ", n);

    // Size of an integer is assumed to be 32 bits 
    for (int i = 15; i >= 0; i--) { 
        int k = n >> i;

        if (i == 7) {
            printf(" ");
        }

        if (k & 1){
            printf("1"); 
            binaryNum[i] = '1';
        }
        else{
            printf("0"); 
            binaryNum[i] = '0';
        }

    } 

    printf("\n");

    unsigned int num = binToDecimal(binaryNum);

    printf("After bits are reversed: \n");

    printf("\t%u = ", num);

    for(int i = 0; i < 16; i++){

        if (i % 8 == 0) {
            printf(" ");
        }

        printf("%c", binaryNum[i]);
    }

    printf("\n");

} 

// main function
int main(){

    unsigned int a;

    printf("Enter an unsigned integer: ");
    scanf("%u", &a);

    printf("Before bits are reversed: \n");


    reverse(a);


}