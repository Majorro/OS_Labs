#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int* arr = calloc(n, sizeof(int));

    for(int i=1; i<n; ++i)
    {
        arr[i] = i;
    }

    printf("Array: ");
    for(int i=0; i<n; ++i)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}