#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>

void* f(void* t_id)
{
	printf("Within thread %ld\n", *(long unsigned int*)t_id);
}

// Unordered threads
void main1()
{
    int n = 3;

    for(int i=0; i<n; i++) 
    {
        pthread_t t_id;

        pthread_create(&t_id, NULL, f, &t_id);
        printf("New thread: %ld\n", t_id);
    }
		
    pthread_exit(0);
}

// Ordered threads
void main2() 
{
    int n = 3;

	for(int i=0; i<n; i++)
    {
		pthread_t t_id;
		
		pthread_create(&t_id, NULL, f, &t_id);
        printf("New thread: %ld\n", t_id);
		// waiting for finish of the previous thread
		pthread_join(t_id, NULL); 
	}
	
	pthread_exit(0);
}

int main()
{
    main1();
    // main2();

	return 0;
}