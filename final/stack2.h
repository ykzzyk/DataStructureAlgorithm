#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct operatorStack{
  char _operator;
  struct operatorStack *nextPtr;
};

struct numStack{
  int num;
  struct numStack *nextPtr;
};


typedef struct operatorStack OperatorStack;
typedef OperatorStack* OperatorStackPtr;

typedef struct numStack NumStack;
typedef NumStack* NumStackPtr;

void operator_push(OperatorStackPtr *ptr, char op){
  OperatorStackPtr newPtr;
  newPtr = malloc(sizeof(OperatorStack));

  if (newPtr != NULL){
    newPtr->_operator = op;
    newPtr->nextPtr = *ptr;
    *ptr = newPtr;
  }
}

char operator_pop(OperatorStackPtr *ptr){

  OperatorStackPtr tempPtr;
  char op;
  tempPtr = *ptr;
  op = (*ptr)->_operator;
  *ptr = (*ptr)->nextPtr;
  free(tempPtr);

  return op;
}

void num_push(NumStackPtr *ptr, int num){
  NumStackPtr newPtr;
  newPtr = malloc(sizeof(NumStackPtr));

  if (newPtr != NULL){
    newPtr->num = num;
    newPtr->nextPtr = *ptr;
    *ptr = newPtr;
  }
}

void print_num_stack(NumStackPtr currentPtr){
  while( currentPtr!= NULL ){
    printf("%d --> ", currentPtr->num);
    currentPtr = currentPtr->nextPtr;
  }
  printf("NULL\n");
}

void print_operator_stack(OperatorStackPtr currentPtr){
  while( currentPtr!= NULL ){
    printf("%c --> ", currentPtr->_operator);
    currentPtr = currentPtr->nextPtr;
  }
  printf("NULL");
}