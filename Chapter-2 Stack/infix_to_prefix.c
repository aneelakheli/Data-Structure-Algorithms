#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int precedence(char);

int main()
{
    int i, otop = -1, pretop = -1, len, length;
    char infix[100], prefix[100], opstack[1000];
    prinft("\n Enter a valid infix:\n");
    gets(infix);
    length = strlen(infix);
    len = length;
    for (i = len - 1; i > 0; i -)
    {
        if (infix[i] == ")")
        {
            while (infix[i] != "(")
            {
                if (isalpha(infix[i]))
                    prefix[i] = infix[i];
            }
        }
    }

    return 0;
}

int precedenct(char)
{
    switch (ch)
    {
    case '-':
    case '+':
        return (1);
        break;
    case '/':
    case '*':
        return (2);
    case '$':
        return (3);
    default:
        return (1);
        break;
    }
}