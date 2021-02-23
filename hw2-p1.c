#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Create a union type
union integer {
    char c;
    short s;
    int i;
    long b;
};

// main function
int main(){

    union integer INT;  

    printf("Enter a character: ");

    scanf("%c", &INT.c);

    printf("'%c' printed as a character is %c\n", INT.c, INT.c);
    printf("'%c' printed as a short integer is %hi\n", INT.c, INT.s);
    printf("'%c' printed as an integer is %d\n", INT.c, INT.i);
    printf("'%c' printed as a long integer is %ld\n", INT.c, INT.b);
    
    printf("\nEnter a short integer: ");

    scanf("%hi", &INT.s);

    printf("'%hi' printed as a character is %c\n", INT.s, INT.c);
    printf("'%hi' printed as a short integer is %hi\n", INT.s, INT.s);
    printf("'%hi' printed as an integer is %d\n", INT.s, INT.i);
    printf("'%hi' printed as a long integer is %ld\n", INT.s, INT.b);

    printf("\nEnter an integer: ");

    scanf("%d", &INT.i);

    printf("'%d' printed as a character is %c\n", INT.i, INT.c);
    printf("'%d' printed as a short integer is %hi\n", INT.i, INT.s);
    printf("'%d' printed as an integer is %d\n", INT.i, INT.i);
    printf("'%d' printed as a long integer is %ld\n", INT.i, INT.b);

    printf("\nEnter a long integer: ");

    scanf("%ld", &INT.b);

    printf("'%ld' printed as a character is %c\n", INT.b, INT.c);
    printf("'%ld' printed as a short integer is %hi\n", INT.b, INT.s);
    printf("'%ld' printed as an integer is %d\n", INT.b, INT.i);
    printf("'%ld' printed as a long integer is %ld\n", INT.b, INT.b);

    return 0;
}