#include<stdio.h>

void swap(int* a, int* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void sort(int arr[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n-i; ++j)
        {
            if(arr[j]>arr[j+1]) swap(&arr[j], &arr[j+1]);
        }
    }
}

int main()
{
    int arr[3] = {3,2,1};
    sort(arr,3);
    for(int i=0;i<3;++i)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}