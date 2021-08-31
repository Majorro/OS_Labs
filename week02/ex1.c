#include<stdio.h>
#include<limits.h>
#include<float.h>

int main()
{
    int i;
    float f;
    double d;
    i = INT_MAX;
    f = FLT_MAX;
    d = DBL_MAX;
    printf("%d %d\n", sizeof(i), i);
    printf("%d %f\n", sizeof(f), f);
    printf("%d %lf\n", sizeof(d), d);
    return 0;
}