#include<stdio.h>
#include<string.h>

const int MAXN = 1000;

void swap(int* a, int* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void sort(int arr[2][MAXN], int n)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j+1 < n-i; ++j)
        {
            if(arr[0][j]>arr[0][j+1])
            {
                swap(&arr[0][j], &arr[0][j+1]);
                swap(&arr[1][j], &arr[1][j+1]);
            }
        }
    }
}

int min(int a, int b)
{
    return (a < b ? a : b);
}

int max(int a, int b)
{
    return (a > b ? a : b);
}

// Trivial algo for the FIFO scheduling: just compute times in order of process arrival
int main()
{
    double atat = 0, awt = 0;
    int n, proc[2][MAXN], ct[MAXN], tat[MAXN], wt[MAXN]; // proc[0] - arrival times; proc[1] - burst times

    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    if(n >= MAXN)
    {
        printf("Too many processes");
        return 0;
    }

    printf("Enter the arrival times of processes in ms, each on the new line:\n");
    for(int i = 0; i < n; ++i)
        scanf("%d", &proc[0][i]);

    printf("Enter the burst times of processes in ms, each on the new line:\n");
    for(int i = 0; i < n; ++i)
        scanf("%d", &proc[1][i]);

    sort(proc, n); // sort to get the initial order of the processes

    for(int i = 0; i < n; ++i)
    {
        if(!i) ct[i] = proc[0][i]+proc[1][i];
        else ct[i] = max(proc[0][i], ct[i-1])+proc[1][i];

        tat[i] = ct[i] - proc[0][i];
        atat += tat[i];

        wt[i] = tat[i] - proc[1][i];
        awt += wt[i];
    }

    atat /= n;
    awt /= n;

    printf("\natat: %lf, awt: %lf\n", atat, awt);
    printf("Processes:\n\n");

    for(int i = 0; i < n; ++i)
    {
        printf("arrival time: %d, burst time: %d\n", proc[0][i], proc[1][i]);
        printf("completion time: %d, turnaround time: %d, waiting time: %d\n\n", ct[i], tat[i], wt[i]);
    }


    return 0;
}