#include<stdio.h>

int main()
{
    const char* path_in = "input.txt";
    FILE* fin_ptr = fopen(path_in, "r");

    const int N=5, M=3;

    int e[M], a[M], c[N][M], r[N][M];
    int tmp;
    char processed[N];

    for(int i=0; i<N; ++i)
        processed[i] = 0;

    for(int i=0; i<M; ++i)
        fscanf(fin_ptr, "%d", &e[i]);

    for(int i=0; i<M; ++i)
        fscanf(fin_ptr, "%d", &a[i]);

    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j)
            fscanf(fin_ptr, "%d", &c[i][j]);

    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j)
            fscanf(fin_ptr, "%d", &r[i][j]);

    char flag = 1;

    while(flag)
    {
        flag = 0;

        for(int i=0; i<N; ++i)
        {
            if(processed[i])
                continue;

            char is_processable = 1;
            for(int j=0; j<M; ++j)
                is_processable &= a[j]>=r[i][j];

            if(is_processable)
            {
                for(int j=0; j<M; ++j)
                {
                    a[j] += c[i][j];
                    r[i][j] += c[i][j];
                    c[i][j] = 0;
                }
                processed[i] = 1;
                flag = 1;
            }
        }
    }

    for(int i=0; i<N; ++i)
    {
        if(!processed[i])
        {
            printf("%d ", i+1);
            flag = 1;
        }
    }

    if(!flag)
        printf("There're no deadlocks");

    fclose(fin_ptr);
    
    return 0;
}