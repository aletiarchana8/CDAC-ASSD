#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *q;
} queue;

int isempty()
{
    return queue.front == -1;
}

int isfull()
{
    return (queue.rear + 1) % queue.size == queue.front;
}

void insert(int ele)
{
    if (isfull())
    {
        printf("Circular Queue Overflow\n");
        return;
    }

    if (isempty())
    {
        queue.front = 0;
        queue.rear = 0;
    }
    else
    {
        queue.rear = (queue.rear + 1) % queue.size;
    }

    queue.q[queue.rear] = ele;

    printf("%d inserted\n", ele);
}

int delete()
{
    int ele;

    if (isempty())
    {
        printf("Circular Queue Underflow\n");
        return -1;
    }

    ele = queue.q[queue.front];

    if (queue.front == queue.rear)
    {
        queue.front = -1;
        queue.rear = -1;
    }
    else
    {
        queue.front = (queue.front + 1) % queue.size;
    }

    return ele;
}

void display()
{
    int i;

    if (isempty())
    {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Circular Queue elements:\n");

    i = queue.front;

    while (1)
    {
        printf("%d ", queue.q[i]);

        if (i == queue.rear)
            break;

        i = (i + 1) % queue.size;
    }

    printf("\n");
}

int main()
{
    int choice, ele;

    queue.front = -1;
    queue.rear = -1;

    printf("Enter queue size: ");
    scanf("%d", &queue.size);

    queue.q = (int *)malloc(queue.size * sizeof(int));

    while (1)
    {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                insert(ele);
                break;

            case 2:
                ele = delete();

                if (ele != -1)
                    printf("Deleted element: %d\n", ele);

                break;

            case 3:
                display();
                break;

            case 4:
                free(queue.q);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
