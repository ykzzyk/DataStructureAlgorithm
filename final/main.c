#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
#include "link.h"

int priority(char* op){
    if (op[0] == '('){
        return 0;
    }
    else if (op[0] == '+' || op[0] == '-'){
        return 1;
    }
    else if (op[0] == '*' || op[0] == '/'){
        return 2;
    }
    return 0;
}

int str_cmp(char input[],char check[])
{
    int i,result=1;
    for(i=0; input[i]!='\0' || check[i]!='\0'; i++) {
        if(input[i] != check[i]) {
            result=0;
            break;
        }
    }
    return result;
}

LinkNodePtr userInput(){
    // (((4+5)/3*5)/5+100/10)-4*3
    // 20-((((4+5)/3*5)/5+100/10)-4)*3  
    // (2+8)/5+3-6*9  
    char str[100] = "", num[10] = "", temp[1] = "";
    int j = 0;
    LinkNodePtr list = NULL;

    printf("Please type an equation (note: no spaces between the equation):\n");
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++){
        if (isalnum(str[i]) == 0){
            if (!str_cmp(num, "")){
                insert(&list, num);
                memset(num,0,sizeof(num));
                j = 0;
            }
            temp[0] = str[i];
            insert(&list, temp);
            memset(temp,0,sizeof(temp));
        }
        else{
            num[j] = str[i];
            j++;
        }

        // Check the end condition
        if (str[i+1] == '\0'){
            if (!str_cmp(num, "")){
                insert(&list, num);
                memset(num,0,sizeof(num));
                j = 0;
            }
        }
        
    }

    return list;

}

int main(void){
    StringStackPtr ptr = NULL; // stack
    StringStackPtr ptr_e = NULL; // stack
    LinkNodePtr list = NULL; // link list
    LinkNodePtr head = NULL; // link list
    LinkNodePtr output = NULL; // link list
    char *data, *op;
    char res[10] = "";

    // Convert the user's input to link list
    list = userInput();

    // Infix to postfix conversion
    head = list;
    while(head != NULL){

        // Process the single item in head
        data = head->str;

        // If the data is not an operator
        if (atoi(data) != 0){
            insert(&output, data);
        }
        else if (str_cmp(data, "(")){
            push(&ptr, data);
        }
        else if (str_cmp(data, ")")){
            while (!str_cmp(op=pop(&ptr), "("))
            {
                insert(&output, op);
            }
        }
        else{
            while((ptr != NULL) && priority(ptr->str) >= priority(data)){
                insert(&output, pop(&ptr));
            }
            push(&ptr, data);
        }

        // Update head to next ptr
        head = head->nextNode;

    }

    while(!isStackEmpty(ptr)){
        insert(&output, pop(&ptr));
    }

    // the postfix equation
    printf("\nThe postfix equation is:\n");
    print_list(output);

    head = output;
    // Evaluation
    while(head != NULL){
        // Process the single item in head
        data = head->str;
        // If the data is not an operator
        if (atoi(data) != 0){
            push(&ptr_e, data);
        }
        // If the data is an operator
        else{
            int b = atoi(pop(&ptr_e));
            int a = atoi(pop(&ptr_e));
            memset(res,0,sizeof(res));

            if (str_cmp(data, "+")){
                sprintf(res, "%d", a+b);
            }
            else if (str_cmp(data, "-")){
                sprintf(res, "%d", a-b);
            }
            else if (str_cmp(data, "*")){
                sprintf(res, "%d", a*b);
            }
            else if (str_cmp(data, "/")){
                sprintf(res, "%d", a/b);
            }
            push(&ptr_e, res);
        }

        // Update head to next ptr
        head = head->nextNode;

    }

    // The final answer is stored in the top of the stack
    printf("\nThe final answer is:\n");
    printf("%s\n", pop(&ptr_e));

}