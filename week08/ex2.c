#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
    int* mem[10];
    for(int i=0; i<10; ++i)
    {
        mem[i] = (int*)malloc(1024*1024); // free memory is decreasing every second
        memset(mem[i], 0, 1024*1024);
        sleep(1);
    }
    sleep(10);
    for(int i=0; i<10; ++i)
        free(mem[i]);
    return 0;
    // si and so are zeros, that means that no processes that are thrashing => no need to swap
    // top also shows that program is consuming virtual and residental memory
}