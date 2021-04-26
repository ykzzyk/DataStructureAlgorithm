#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

int cal_priority(char op){

    if (op == '(' || op == ')'){
        return 4;
    }
    else if (op == '*' || op == '/'){
        return 2;
    }
    else if (op == '+' || op == '-'){
        return 1;
    }
    return 0;
}



int main(void){
    
    char* s[100] = {"20", "-", "(", "5",
                    "*", "(", "3", "+",
                    "(", "80", "/", "20",
                    ")", ")", "+", "6", ")"};

    // char* s[100] = {"2", "*", "(", "3",
    //                 "+", "4", ")", "*",
    //                 "5"};

    char* p[100] = {};

    char op = ' ';
    int j = 0;
    int cnt = 0, cur = 0, pre = -1;

    OperatorStackPtr ptr_op = NULL;

    for(int i = 0; s[i] != (void *)0; i++){
        // s[i] is not an operator
        if (atoi(s[i]) != 0){
            p[j] = s[i]; 
            printf("0 j: %d\n", j);
            j++; 
            printf("the p is now: %s\n", p[j-1]);
        }
        // s[i] is an operator
        else if (atoi(s[i]) == 0){
            
            operator_push(&ptr_op, *s[i]);

            print_operator_stack(ptr_op);
            printf("\n");

            if (*s[i] == '('){
                cnt+=1;
                if (*s[i-1] == '-'){
                    pre = 5;
                }
            }
            else if (*s[i] == ')'){
                op = ' ';
                while(op != '('){
                    op = operator_pop(&ptr_op);
                    if ((op != ')') && (op != '(')){
                        char temp[2] = {op, '\0'};
                        p[j] = temp; 
                        printf("else if j: %d\n", j);
                        j++;
                        printf("the p + is now: %s\n", p[j-1]);
                    }
                    pre = cal_priority(op);
                }
                cnt-=1;
                print_operator_stack(ptr_op);
                printf("\n");
                if (cnt > 0){
                    continue;
                }
            }
            else{
                if (cnt == 0){
                    cur = cal_priority(*s[i]);
                    printf("cur, %c: %d; pre, %d\n", *s[i], cur, pre);
                    while ((cur - pre < 0) && (ptr_op != NULL)){
                        op = operator_pop(&ptr_op);
                        pre = cal_priority(op);
                        printf("pre, %c: %d\n", op, pre);
                        char temp[2] = {op, '\0'};
                        p[j] = temp;
                        printf("j: %d\n", j);
                        j++;
                        printf("the op p is now: %s\n", p[j-1]);
                    }
                }
            }
        }
    }

    while(ptr_op!=NULL){
        op = operator_pop(&ptr_op);
        p[j] = &op; 
        j++;
    }

    int i = 0;
    printf("\nThe postfix expression is demonstrated below:\n");
    while(p[i] != (void *)0){
        printf("%s ", p[i]); i++;
    }

    printf("\n");
    return 0;

}