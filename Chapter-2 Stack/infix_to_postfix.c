// A c program to convert an expression from infix to postfix
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int precendency(char);

void main(){
    int i, otop=-1,ptop=-1, len, length;
    char infix[100], postfix[100], opstack[100];
    printf("\n Enter a valid infix \n");
    gets(infix); //scanf("% s",&infix); (A+B*C)
    length = strlen(infix);
    len = length;
    for(i=0;i<length;i++){
        if(infix[i]=='('){

            opstack[++otop] = infix[i];
            len++;
        }
        else if (isalpha(infix[i])){
            postfix[++ptop] =infix[i];
        }
        else if(infix[i] ==')'){
            len++;
            while(opstack[otop]!='('){
                postfix[++ptop] =opstack[otop];
                otop--;
            }
            otop--;
        }
        else {
            if(precedency(opstack[otop])>=precedency(infix[i]) ){
                postfix[++ptop] = opstack[otop--];
                opstack[++otop] = infix[i];
            }

        }
    }
    while(otop !=-1){
        postfix[++ptop] ==opstack[otop];
        otop--;
    }
    for(i=0;i<len;i++){
        printf("%c", postfix[i]);
    }
getch();


}

int precedency(chat ch){
    switch(ch){
        case '$':
            return (4);

        case '/':
        case '*':
          return (3);
        case '-':
        case '+':
            return (2);
        default:
            return 1;
    }
}
