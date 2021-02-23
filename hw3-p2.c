#include <stdio.h>
#include <stdlib.h>


int main(){
  int i = 0;
  int num = 0;
  int sum = 0;
  char ch[10000];

  for (i = 0; i < 4; i++){
    printf("Enter an integer string: ");
    gets(ch);
    num = atoi(ch);
    sum += num;
  }

  printf("The total of the value is %d\n", sum);
}