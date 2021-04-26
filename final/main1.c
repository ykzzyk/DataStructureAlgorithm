#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

int cal_priority(char op){

    if (op == '('){
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
    printf("please type in the equation:\n");

    // Initialize the stack
    OperatorStackPtr ptr_op = NULL;

    // char *s = "20+17*(90+8)/3*2";

    char* s[100] = {"20", "-", "(", "5",
                    "*", "(", "3", "+",
                    "(", "80", "/", "20",
                    ")", ")", "+", "6", ")"};

    // char* s[100] = {"2", "*", "(", "3",
    //                 "+", "4", ")", "*",
    //                 "5"};

    char* p[100] = {};

    char op;

    // printf("%s", s);

    int i = 0;
    int j = 0;
    int cnt = 0;
    int pre_periority = 0;
    bool parentheses = false;

    while(s[i] != (void *)0){

        // Print out the current element
        printf("%s\n", s[i]);

        if ((atoi(s[i]) == 0)){
            printf("\noperators: %s\n", s[i]);
            if (*s[i] == '('){
                operator_push(&ptr_op, *s[i]);
                parentheses = true;
                cnt+=1;
            }
            if (*s[i] == ')'){
                while(1){
                    op = operator_pop(&ptr_op);
                    if (op == '('){
                        cnt-=1;
                        break;
                    }
                    else if(op == '+'){
                        p[j] = "+";
                    }
                    else if(op == '-'){
                        p[j] = "-";
                    }
                    else if(op == '*'){
                        p[j] = "*";
                    }
                    else if(op == '/'){
                        p[j] = "/";
                    }
                    
                    // printf("j: %d\n", j);
                    // printf("op: being poped %c\n", op);
                    j++;
                    // printf("op: being poped %s\n", &op);
                    // printf("1op: after being poped %s\n", p[j-1]);
                    
                }
                if (cnt == 0){
                    parentheses = false;
                    i++;
                    continue;
                }
            }
            if (parentheses && *s[i] != '('){
                if (*s[i] != ')')
                    operator_push(&ptr_op, *s[i]);
            }
            if (!parentheses){

                operator_push(&ptr_op, *s[i]);

                if (*s[i] == '-' && *s[i+1] == '(')
                    pre_periority = 5;
                print_operator_stack(ptr_op);
                printf("hhhh");

                printf("pre_periority: %d\n", pre_periority);
                printf("cal_priority(*s[i]): %d\n", cal_priority(*s[i]));
                // printf("diff cal_priority(*s[i]): %d\n", pre_periority-cal_priority(*s[i]));
                
                if (pre_periority - cal_priority(*s[i]) >= 0){
                    printf("true\n");
                    print_operator_stack(ptr_op);
                    op = operator_pop(&ptr_op);
                    printf("op: %c", op);
                    p[j] = &op; j++;
                    // printf("2op: after being poped %s\n\n\n", p[j-1]);
                    pre_periority = cal_priority(*s[i]);
                    printf("pre_periority: %d\n", pre_periority);
                }

                
            }
            
        }
        else{
            p[j] = s[i]; j++;
        }
        i++;
    }
      
    while(ptr_op!=NULL){
        op = operator_pop(&ptr_op);
        p[j] = &op; j++;
    }

    i = 0;
    printf("\nThe postfix expression is demonstrated below:\n");
    while(p[i] != (void *)0){
        printf("%s ", p[i]); i++;
    }

    printf("\n");
    return 0;
}