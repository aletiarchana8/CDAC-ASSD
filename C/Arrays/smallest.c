#include <stdio.h>

int main()
{
    int a[100], n, i, smallest;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    smallest = a[0];

    for(i = 1; i < n; i++)
    {
        if(a[i] < smallest)
            smallest = a[i];
    }

    printf("Smallest = %d\n", smallest);

    return 0;
}
