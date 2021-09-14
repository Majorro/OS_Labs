#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    while(1)
    {
        fork();
        fork();
        fork();
        // fork();
        // fork();
        sleep(5);
    }

    return 0;
}

// each fork creates new process in which the next forks create new processes, the initial process branches 3 processes,
// then the first fork branches 2 and the second one more, and so on; with 5 fork calls there will be more branches
// in the same way