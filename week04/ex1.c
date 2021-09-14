#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    int pid = getpid();
    printf("Hello from parent [PID - %d]\n", getpid());
    fork();
    if(getpid()!=pid)
        printf("Hello from child [PID - %d]\n", getpid());
    return 0;
}

// every new process gets new pid which differs by one from the previous, so they are unique