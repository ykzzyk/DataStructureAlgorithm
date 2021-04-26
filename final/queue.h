#include <stdio.h>
#include <stdlib.h>

struct queueNode{
    char* data;
    struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char* data){


    QueueNodePtr newPtr;

    newPtr = (QueneNode*) malloc(sizeof(QueueNode))
}