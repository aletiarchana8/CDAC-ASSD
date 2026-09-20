#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

char peek()
{
    if (stack.tos == -1)
        return '\0';

    return stack.s[stack.tos];
}

int isempty()
{
    return stack.tos == -1;
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

void reverse(char str[])
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main()
{
    char infix[100], prefix[100];
    int i, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    reverse(infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    stack.size = strlen(infix);
    stack.tos = -1;

    stack.s = (char *)malloc(stack.size * sizeof(char));

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            prefix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (!isempty() && peek() != '(')
            {
                prefix[j++] = pop();
            }

            if (!isempty())
                pop();
        }
        else
        {
            while (!isempty() &&
                   peek() != '(' &&
                   precedence(peek()) > precedence(ch))
            {
                prefix[j++] = pop();
            }

            push(ch);
        }
    }

    while (!isempty())
    {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';

    reverse(prefix);

    printf("Prefix expression: %s\n", prefix);

    free(stack.s);

    return 0;
}
