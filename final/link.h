#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct linkNode
{
    char* str;
    struct linkNode *nextNode;
};

typedef struct linkNode LinkNode;
typedef LinkNode *LinkNodePtr;

void insert (LinkNodePtr *ptr, char* value){
    LinkNodePtr newPtr;
    LinkNodePtr previousPtr;
    LinkNodePtr currentPtr;
    char *copy = malloc(strlen(value) + 1);
    strcpy(copy, value);

    newPtr = malloc(sizeof(LinkNode));
    newPtr->str = copy;
    newPtr->nextNode = NULL;

    previousPtr = NULL;
    currentPtr = *ptr;

    while (currentPtr != NULL)
    {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextNode;
    }

    if (previousPtr == NULL){
        newPtr->nextNode = *ptr;
        *ptr = newPtr;
    }else{
        previousPtr -> nextNode = newPtr;
        newPtr->nextNode = currentPtr;
    }
    

}

int isLinkEmpty(LinkNodePtr ptr){
    return ptr == NULL;
}

void print_list(LinkNodePtr ptr){
    while(ptr != NULL){
        printf("%s ", ptr->str);
        ptr = ptr->nextNode;
    }
    printf("--> NULL\n");
}

void str2link(LinkNodePtr *ptr, char* arr[]){
    for (int i = 0; arr[i] != (void *)0; i++){
        insert(ptr, arr[i]);
    }
}
// char* delete(LinkNodePtr *ptr, char* value){
//     LinkNodePtr previousPtr;
//     LinkNodePtr currentPtr;
//     LinkNodePtr tempPtr;

//     if (value == (*sPtr)->data){

//     }
// }