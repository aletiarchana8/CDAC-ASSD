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

int main()
{
    char infix[100], postfix[100];
    int i, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    stack.size = strlen(infix);
    stack.tos = -1;

    stack.s = (char *)malloc(stack.size * sizeof(char));

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (!isempty() && peek() != '(')
            {
                postfix[j++] = pop();
            }

            if (!isempty())
                pop();
        }
        else
        {
            while (!isempty() &&
                   peek() != '(' &&
                   precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (!isempty())
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    free(stack.s);

    return 0;
}
