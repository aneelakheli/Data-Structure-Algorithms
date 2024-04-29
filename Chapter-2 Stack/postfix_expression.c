#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

void push(int);
int pop();
int vstack[100];
int tos = -1;
int main(){
    int i, res, len, op1, op2, value[100];
    char postfix[100], ch;
    printf("Enter a valid postfix \n");
    gets(postfix);
    len = strlen(postfix);
    for(i =0;i<=len-1;i++){
        if(isalpha(postfix[i])){
            printf("Enter value of %c \n", postfix[i]);
            scanf("%d", &value[i]);
            push(value[i]);
        }
        else{
            ch = postfix[i];
            op2 = pop();
            printf("The value of operator2 is\n",op2);
            op1 =pop();
            printf("The value of operator1 is\n",op1);
            switch(ch){
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 +op2);
                    break;
                case '*':
                    push(op1 +op2);
                    break;
                case '/':
                    push(op1 +op2);
                    break;
                case '$':
                    push(op1 +op2);
                    break;
                case '%':
                    push(op1 +op2);
                    break;
            }
        }
    }
    printf("The result is:");
    res = pop();
    printf("%d", res);
    return 0;
}

void push(int val){

    vstack[++tos] = val;
}

int pop(){
    int n;
    n = vstack[tos--];
    return(n);
}
