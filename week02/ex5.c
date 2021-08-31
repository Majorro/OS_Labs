#include<stdio.h>
#include<string.h>

void print_isosceles_triangle(int n)
{
    void print_line(int n, int nstars)
    {
        for(int i = 0; i < n-(nstars+1)/2; ++i)
            putchar(' ');
        for(int i = 0; i < nstars; ++i)
            putchar('*');
        putchar('\n');
    }

    for(int i = 0; i < n; ++i)
        print_line(n, i*2+1);
}

void print_rectangle(int n, int m)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
            putchar('*');
        putchar('\n');
    }
}

int main()
{
    int n, m;
    printf("Write two numbers to print some figure: ");
    scanf("%d %d", &n, &m);
    if(m==n*2-1) print_isosceles_triangle(n);
    else print_rectangle(n,m);
    return 0;
}