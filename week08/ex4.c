#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
    struct rusage usage;

    int* mem[10];
    for(int i=0; i<10; ++i)
    {
        mem[i] = (int*)malloc(1024*1024);
        memset(mem[i], 0, 1024*1024);

        getrusage(RUSAGE_SELF, &usage);
        printf("Maximum resident size: %ld\n", usage.ru_maxrss);

        sleep(1);
    }
    sleep(10);
    for(int i=0; i<10; ++i)
        free(mem[i]);
    return 0;
}