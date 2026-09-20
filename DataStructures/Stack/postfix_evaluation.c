#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct stack
{
    int size;
    int tos;
    int *s;
} stack;

void push(int ele)
{
    stack.s[++stack.tos] = ele;
}

int pop()
{
    if (stack.tos == -1)
        return -1;

    return stack.s[stack.tos--];
}

int isempty()
{
    return stack.tos == -1;
}

int main()
{
    char exp[100];
    int i, a, b, result;
    char ch;

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    stack.size = strlen(exp);
    stack.tos = -1;

    stack.s = (int *)malloc(stack.size * sizeof(int));

    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch (ch)
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                default:
                    printf("Invalid operator\n");
                    free(stack.s);
                    return 1;
            }

            push(result);
        }
    }

    if (!isempty())
    {
        result = pop();
        printf("Result = %d\n", result);
    }

    free(stack.s);

    return 0;
}
