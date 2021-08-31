#include<stdio.h>
#include<string.h>

const int INF=50;

void swap(char* a, char* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main()
{
    char buf[INF];
    printf("Input a string with the length less than %d: ", INF);
    scanf("%s",buf);
    int len = strlen(buf);
    for(int i = 0; i < len/2; ++i)
        swap(&buf[i], &buf[len-i-1]);
    printf("Reversed: %s", buf);

    return 0;
}