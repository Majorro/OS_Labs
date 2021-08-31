#include<stdio.h>
#include<string.h>

void print_line(int n, int nstars)
{
    for(int i = 0; i < n-(nstars+1)/2; ++i)
        putchar(' ');
    for(int i = 0; i < nstars; ++i)
        putchar('*');
    putchar('\n');
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        print_line(n, i*2+1);
    return 0;
}