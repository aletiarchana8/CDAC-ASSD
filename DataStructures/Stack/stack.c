#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int tos;
    int *s;
} stack;

void push(int ele)
{
    if (stack.tos == stack.size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack.s[++stack.tos] = ele;
        printf("%d pushed into stack\n", ele);
    }
}

int pop()
{
    if (stack.tos == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return stack.s[stack.tos--];
    }
}

int peek()
{
    if (stack.tos == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return stack.s[stack.tos];
    }
}

void display()
{
    int i;

    if (stack.tos == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements:\n");

        for (i = stack.tos; i >= 0; i--)
        {
            printf("%d\n", stack.s[i]);
        }
    }
}

int main()
{
    int choice, ele;

    stack.tos = -1;

    printf("Enter stack size: ");
    scanf("%d", &stack.size);

    stack.s = (int *)malloc(stack.size * sizeof(int));

    while (1)
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                push(ele);
                break;

            case 2:
                ele = pop();

                if (ele != -1)
                    printf("Popped element: %d\n", ele);

                break;

            case 3:
                ele = peek();

                if (ele != -1)
                    printf("Top element: %d\n", ele);

                break;

            case 4:
                display();
                break;

            case 5:
                free(stack.s);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
