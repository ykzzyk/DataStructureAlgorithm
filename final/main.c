#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"
#include "link.h"

int priority(char* op){
    if (op[0] == '(' || op[0] == ')'){
        return 4;
    }
    else if (op[0] == '*' || op[0] == '/'){
        return 2;
    }
    else if (op[0] == '+' || op[0] == '-'){
        return 1;
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

int main(void){
    StringStackPtr ptr = NULL;
    LinkNodePtr list = NULL;
    LinkNodePtr head = NULL;
    LinkNodePtr output = NULL;
    char* data, *op;
    int cnt = 0, pre_prio = 0, cur_prio = 0;

    // char* s[100] = {"20", "-", "(", "5",
    //                 "*", "(", "3", "+",
    //                 "(", "80", "/", "20",
    //                 ")", ")", "+", "6", ")"};


    char* s[100] = {"2", "+", "(", "(", "8", "+", "12", ")", "/", "10", "-", "3", ")", "*", "5"};

    // char* s[100] = {"(", "2", "+", "8", ")", "/", "5", "+", "3", "-", "6", "*", "9"};

    // char* s[100] = {"2", "*", "(", "3",
    //                 "+", "4", ")", "*",
    //                 "5"};

    // char* s[100] = {"(", "(", "(", "4", "+", "5", ")", "/", "3", "*", "5", ")",
    //                 "/", "5", "+", "100", "/", "10", ")", "-", "4", "*", "3"};

    // char* s[100] = {"20", "-", "(", "(", "(", "(", "4", "+", "5", ")", "/", "3", "*", "5", ")",
    //                "/", "5", "+", "100", "/", "10", ")", "-", "4", ")", "*", "3"};

    // (((4+5)/3*5)/5+100/10)-4*3
    // 20-((((4+5)/3*5)/5+100/10)-4)*3     

    str2link(&list, s);
    
    // print_list(list);

    head = list;
    while(head != NULL){

        // Process the single item in head
        data = head->str;

        // If the data is not an operator
        if (atoi(data) != 0){
            insert(&output, data);
        }
        // Else, data is an operator
        else{
            if (!isStackEmpty(ptr)){pre_prio = priority(ptr->str);}
            else{pre_prio = 0;}
            
            // If operator is (, then increase cnt by 1
            if (str_cmp(data, "(")){
                cnt += 1;
                if (!isStackEmpty(ptr)){
                    if (str_cmp(ptr->str, "-")){
                        op = pop(&ptr);
                        insert(&output, op);
                    }
                }
                
            }
            // else if the operator is ), the decrease the cnt by 1
            else if (str_cmp(data, ")")){
                op = " ";
                while(!str_cmp(op, "(") && (!isStackEmpty(ptr))){
                    op = pop(&ptr);
                    // Only if the operators are not parentheses, 
                    // we insert it into the output list
                    if (!str_cmp(op, "(")){
                        insert(&output, op);
                    }
                }
                cnt -= 1;
                if (cnt > 0){continue;}
            }
            // else, if there no parentheses
            else{
                if (cnt == 0 && !isStackEmpty(ptr)){
                    cur_prio = priority(data);
                    printf("current data: %s, %d\n", data, cur_prio);
                    printf("diff, %d\n", (cur_prio - pre_prio));
                    while((cur_prio - pre_prio <= 0) && (!isStackEmpty(ptr))){
                        printf("in while: %s, %d\n", data, cur_prio);

                        op = pop(&ptr);
                        insert(&output, op);

                        if (!isStackEmpty(ptr)){pre_prio = priority(ptr->str);}
                        else{pre_prio = 0;}
                    }
                }
            }
            if (!str_cmp(data, ")")){
                push(&ptr, data);
                cur_prio = priority(ptr->str);
            }
        }

        // Update head to next ptr
        head = head->nextNode;

    }

    while(!isStackEmpty(ptr)){
        op = pop(&ptr);
        insert(&output, op);
    }

    print_list(output);
    
}