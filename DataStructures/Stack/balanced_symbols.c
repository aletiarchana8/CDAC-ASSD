#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int tos;
    char *s;
} stack;

void push(char ch)
{
    stack.s[++stack.tos] = ch;
}

char pop()
{
    if (stack.tos == -1)
        return '\0';

    return stack.s[stack.tos--];
}

int isempty()
{
    return stack.tos == -1;
}

int ismatching(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;

    if (open == '{' && close == '}')
        return 1;

    if (open == '[' && close == ']')
        return 1;

    return 0;
}

int main()
{
    char exp[100];
    char ch, open;
    int i, balanced = 1;

    printf("Enter expression: ");
    scanf("%s", exp);

    stack.size = strlen(exp);
    stack.tos = -1;

    stack.s = (char *)malloc(stack.size * sizeof(char));

    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (isempty())
            {
                balanced = 0;
                break;
            }

            open = pop();

            if (!ismatching(open, ch))
            {
                balanced = 0;
                break;
            }
        }
    }

    if (!isempty())
        balanced = 0;

    if (balanced)
        printf("Balanced Symbols\n");
    else
        printf("Not Balanced Symbols\n");

    free(stack.s);

    return 0;
}
