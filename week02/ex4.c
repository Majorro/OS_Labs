#include<stdio.h>

void swap(int* a, int* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main()
{
    int a,b;
    printf("Write two integers to swap: ");
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("Swapped integers: %d %d", a, b);
    return 0;
}