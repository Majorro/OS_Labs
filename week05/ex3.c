#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

#define capacity 10

int counter = 0;
int buffer[capacity];

int data_cons = 0;
int data_prod = 0;


void* consume(void *t_id)
{
	while(1)
	{
		while(counter <= 0);

		buffer[counter] = data_cons;

        if(buffer[counter] != data_cons)
		{
			printf("Race condition occured in consume function\n");
			exit(1);
		}

        counter--; data_cons++;
	}
}

void* produce(void *t_id)
{
	while(1)
	{
		while(counter+1 >= capacity);

		buffer[counter] = data_prod;

        if(buffer[counter] != data_prod)
		{
			printf("Race condition occured in produce function\n");
			exit(1);
		}
        
        ++counter; ++data_prod;
	}
}

int main()
{
	pthread_t produce_t_id, consume_t_id;

	pthread_create(&consume_t_id, NULL, consume, NULL);
	pthread_create(&produce_t_id, NULL, produce, NULL);

	pthread_join(consume_t_id, NULL);
	pthread_join(produce_t_id, NULL);
	
	pthread_exit(0);
	
	return 0;
}