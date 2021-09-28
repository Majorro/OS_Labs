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

// Round robin algo: execute processes consequently by arrival time, but each process has restricted executing time(quantum)
// after which scheduler executes the next process until all processes will be executed. Then, remained
// processes will be executed one by one with restriction and so on.
int main()
{
    double atat = 0, awt = 0;
    int n, quantum, proc[2][MAXN], ct[MAXN], tat[MAXN], wt[MAXN], rem_bt[MAXN]; // proc[0] - arrival times; proc[1] - burst times
    char used[MAXN];

    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    printf("Enter the quantum(size of chunk):\n");
    scanf("%d", &quantum);

    if(n >= MAXN)
    {
        printf("Too many processes");
        return 0;
    }

    for(int i = 0; i < n; ++i) // array initialization
    {
        ct[i] = 0;
        tat[i] = 0;
        wt[i] = 0;
        used[i] = 0;
        rem_bt[i] = 0;
    }

    printf("Enter the arrival times of processes in ms, each on the new line:\n");
    for(int i = 0; i < n; ++i)
        scanf("%d", &proc[0][i]);

    printf("Enter the burst times of processes in ms, each on the new line:\n");
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &proc[1][i]);
        rem_bt[i] = proc[1][i];
    }

    sort(proc, n); // sort to get the initial order of the processes

    int time = 0;
    char flag = 1;
    while(flag)
    {
        flag = 0;
 
        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i])
            {
                flag = 1;

                time += min(quantum, rem_bt[i]);
                rem_bt[i] -= min(quantum, rem_bt[i]);

                awt -= wt[i];          
                wt[i] = time - proc[1][i];
                awt += wt[i];

                atat -= tat[i];
                tat[i] = proc[1][i] + wt[i];
                atat += tat[i];

                ct[i] = proc[0][i] + tat[i];

            }
        }
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