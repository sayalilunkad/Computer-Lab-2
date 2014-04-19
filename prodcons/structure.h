#include<semaphore.h>
#include<pthread.h>

struct buffer{
	int data[100];
	pthread_mutex_t var;
	sem_t full, empty;
};
