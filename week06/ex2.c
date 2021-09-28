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

// Algo for the SJF scheduling is similar to FIFO, but we don't take the next element, but choose from several next elements
// which have at<=ct of the executed process.
int main()
{
    double atat = 0, awt = 0;
    int n, proc[2][MAXN], ct[MAXN], tat[MAXN], wt[MAXN]; // proc[0] - arrival times; proc[1] - burst times
    char used[MAXN];

    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    if(n >= MAXN)
    {
        printf("Too many processes");
        return 0;
    }

    for(int i = 0; i < n; ++i) // array initialization
    {
        ct[i] = 0;
        used[i] = 0;
    }

    printf("Enter the arrival times of processes in ms, each on the new line:\n");
    for(int i = 0; i < n; ++i)
        scanf("%d", &proc[0][i]);

    printf("Enter the burst times of processes in ms, each on the new line:\n");
    for(int i = 0; i < n; ++i)
        scanf("%d", &proc[1][i]);

    sort(proc, n); // sort to get the initial order of the processes

    int cur=0,prev=0;
    while(1)
    {
        // searching for the fastest process in queue
        for(int i = 0; i < n && proc[0][i] <= ct[prev]; ++i)
        {
            if(!used[i] && (!cur || cur == prev || proc[1][i] < proc[1][cur]))
                cur = i;
        }

        while(cur < n && cur && (cur == prev || used[cur])) // if there's no processes in queue at the moment of prev process completion
            ++cur;

        if(cur >= n) // all processes executed
            break;

        used[cur] = 1;

        ct[cur] = max(proc[0][cur], ct[prev])+proc[1][cur];

        tat[cur] = ct[cur] - proc[0][cur];
        atat += tat[cur];

        wt[cur] = tat[cur] - proc[1][cur];
        awt += wt[cur];

        prev = cur;
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