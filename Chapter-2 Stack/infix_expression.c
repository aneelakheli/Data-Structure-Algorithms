#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void push(int);
int pop();
int vstack[100];
int tos =-1;

int main(){
    int i, res, l, op1, op2, value[100];
    char prefix[100], ch;
    printf("\n Enter a valid prefix: ");
    gets(prefix);
    l = strlen(prefix);
    for(i=l-1; i>=0;i++){
        if(isalpha(prefix[i])){
            printf("\n Enter value of %c", prefix[i]);
            scanf("%d", &value[i]);
            push(value[i]);
        }
        else if(prefix[i]=='*' || prefix[i]=='/' || prefix[i]=='+' || prefix[i]=='-' || prefix[i]=='%' || prefix[i]=='$'){
            ch = prefix[i];
            op1= pop();
            op2 = pop();
            switch(ch){
                case '+':
                    push(op1 +op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
                case '$':
                    push(power(op1,op2));
                    break;
                case '%':
                    push(op1 %op2);
                    break;
                }

        }
    }

    printf("\n The Result is: ");
    res = pop();
    printf("%d", res);
    return 0;
}

void push(int val){
    vstack[++tos] = val;
}

int pop(){
    int n;
    n= vstack[tos--];
    return(n);
}


int power(int base, int exponent) {
    int result = 1;
    while (exponent != 0) {
        if (exponent > 0) {
            result *= base;
            exponent--;
        } else {
            result /= base;
            exponent++;
        }
    }
    return result;
}
