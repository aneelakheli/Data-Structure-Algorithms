// C program to convert an expression from infix to prefix expression

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int precendency(char);

int main()
{
    int i, optos = -1, pretos = -1, len, length;
    char infix[100], prestack[100], opstack[100];
    printf("Enter a valid infix\n");
    gets(infix);
    length = strlen(infix);
    len = length;
    printf("here");
    for (i = length - 1; i >= 0; i++)
    {
        if (infix[i] == ')')
        {
            opstack[++optos] = infix[i];
            len++;
        }
        else if (isalpha(infix[i]))
        {
            prestack[++pretos] = infix[i];
        }
        else if (infix[i] == '(')
        {
            len++;
            while (opstack[optos] != ')')
            {
                prestack[++pretos] = opstack[optos];
                optos--;
            }
            optos--;
        }
        else
        {
            if (precendency(opstack[optos]) > precendency(infix[i]))
            {
                prestack[++pretos] == opstack[optos--];
                opstack[++optos] = infix[i];
            }
            opstack[++optos] = infix[i];
        }
    }
    while (optos != -1)
    {
        prestack[++pretos] = opstack[optos];
        optos--;
    }
    for (i = len - 1; i >= 0; i++)
    {
        printf("%c", prestack[i]);
    }

    return 0;
}

int precendency(char character)
{
    switch (character)
    {
    case '$':
        return (4);
    case '*':
    case '/':
        return (3);
    case '+':
    case '-':
        return (2);
    default:
        return (1);
    }
}
