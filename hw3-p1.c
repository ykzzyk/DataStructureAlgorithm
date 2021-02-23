#include <stdio.h>
#include <stdlib.h>


int main(){
    char arrays[100];

    printf("Enter a line of text:\n");
    gets(arrays);
    
    printf("\nThe line in uppercase is:\n");
    for(int i=0; arrays[i]!='\0'; i++)
    {
        if(arrays[i]>='a' && arrays[i]<='z')
        {
            arrays[i] = arrays[i] - 32;
        }

        printf("%c", arrays[i]);
    }

    printf("\n\nThe line in lowercase is:\n");
    for(int i=0; arrays[i]!='\0'; i++)
    {
        if(arrays[i] >= 'A' && arrays[i]<='a')
        {
            arrays[i] = arrays[i] + 32;
        }

        printf("%c", arrays[i]);
    }

    return 0;
}