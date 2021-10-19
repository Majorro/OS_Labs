#include<stdio.h>
#include<limits.h>

int main()
{
    const char* path_in = "input.txt";
    const int MAXN = 1e6;

    int page_table[MAXN], recent_ref_queues[MAXN];
    FILE* fin_ptr = fopen(path_in, "r");

    int n, cur_ref, hit_cnt=0, miss_cnt=0;
    scanf("%d", &n);

    for(int i=0; i<n; ++i)
    {
        page_table[i] = -1;
        recent_ref_queues[i] = 0;
    }

    while(fscanf(fin_ptr, "%d", &cur_ref) == 1)
    {
        char is_hit = 0;

        // checking for the ref presence
        for(int i=0; i<n; ++i)
        {
            if(page_table[i] == cur_ref)
            {
                ++hit_cnt;
                is_hit = 1;
                break;
            }
        }

        // page fault
        if(!is_hit)
        {
            char frame_found = 0;
            ++miss_cnt;

            for(int i=0; i<n; ++i) // searching for a free page frame
            {
                if(page_table[i] == -1)
                {
                    page_table[i] = cur_ref;
                    frame_found = 1;
                    break;
                }
            }

            if(!frame_found)
            {
                int lst_rec_used_ref_frame, min_occurence = INT_MAX;

                for(int i=0; i<n; ++i) // searching for the least recently used page reference
                {
                    if(page_table[i] != -1 && 
                       min_occurence > recent_ref_queues[page_table[i]])
                    {
                        min_occurence = recent_ref_queues[page_table[i]];
                        lst_rec_used_ref_frame = i;
                    }
                }

                page_table[lst_rec_used_ref_frame] = cur_ref;
            }
        }

        for(int i = 0; i < n; ++i) // recent refs update
        {
            if(page_table[i] != -1)
            {
                recent_ref_queues[page_table[i]] >>= 1;

                if(page_table[i] == cur_ref)
                {
                    recent_ref_queues[page_table[i]] |= 1<<31;
                }
            }
        }
    }

    printf("Hit: %d\nMiss: %d\nHit/Miss ratio: %lf\n",
            hit_cnt, miss_cnt, (double)hit_cnt/miss_cnt);
}