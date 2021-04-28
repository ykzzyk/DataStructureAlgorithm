#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct stringStack{
  char* str;
  struct stringStack *nextPtr;
};

typedef struct stringStack StringStack;
typedef StringStack *StringStackPtr;

void push(StringStackPtr *ptr, char* data){

  StringStackPtr newPtr;
  newPtr = malloc(sizeof(StringStack));

  char * copy = malloc(strlen(data) + 1); 
  strcpy(copy, data);

  if (newPtr != NULL){
    newPtr->str = copy;
    newPtr->nextPtr = *ptr;
    *ptr = newPtr;
  }
}

char* pop(StringStackPtr *ptr){

  StringStackPtr tempPtr;
  char* data;
  tempPtr = *ptr;
  data = (*ptr)->str;
  *ptr = (*ptr)->nextPtr;
  free(tempPtr);

  return data;
}

void print_stack(StringStackPtr currentPtr){
  while( currentPtr!= NULL ){
    printf("%s --> ", currentPtr->str);
    currentPtr = currentPtr->nextPtr;
  }
  printf("NULL\n");
}

int isStackEmpty(StringStackPtr ptr){
  return (ptr == NULL);
}