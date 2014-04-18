#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t id[3];
int clock_t_1=0, clock_t_2=0, clock_t_3=0;

void *increment1
void *clock1(void *interval)
{
	pthread_t id1;
	int *intr = (void*)interval;
	pthread_create(&id1, NULL, &increment1, interval);


}

main()
{
	int interval[3];
	interval[0]=5;
	interval[1]=10;
	interval[2]=15;

	pthread_create(&id[0], NULL, &clock1, (void *)&interval[0]);
	pthread_create(&id[1], NULL, &clock2, (void *)&interval[1]);
	pthread_create(&id[2], NULL, &clock3, (void *)&interval[2]);

	pthread_join(id[0], NULL);
	pthread_join(id[1], NULL);
	pthread_join(id[2], NULL);
	
}

