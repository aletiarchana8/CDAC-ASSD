#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *q;
} queue;

void insert(int ele)
{
    if (queue.rear == queue.size - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        queue.q[++queue.rear] = ele;
        printf("%d inserted\n", ele);
    }
}

int delete()
{
    int ele;

    if (queue.front == queue.rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        ele = queue.q[++queue.front];
        return ele;
    }
}

void display()
{
    int i;

    if (queue.front == queue.rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements:\n");

        for (i = queue.front + 1; i <= queue.rear; i++)
        {
            printf("%d ", queue.q[i]);
        }

        printf("\n");
    }
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
        printf("\n--- QUEUE MENU ---\n");
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
