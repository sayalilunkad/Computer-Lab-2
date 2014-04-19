#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include"structure.h"

int main()
{

        int key=1111,shmid;
	char *ptr;
	struct buffer *shm;
	int n=0;
	// Get read access to shared segment
	if((shmid = shmget(key, 10, 0666)) == -1)
	{
		perror("\nshmget");
		exit(0);
	}
	// Attach to process address space
	if((ptr = shmat(shmid, NULL, 0)) == (char *)-1)
	{
		perror("\nshmat");
		exit(0);
	}
	
	shm = (struct buffer *)ptr;
	
	while(1)
	{
		//lock semaphore		
		sem_wait(&(shm->full));
		//Mutex lock
		pthread_mutex_lock(&(shm->var));
		
		printf("\nConsumer consumes: %d",shm->data[n]);
		n++;
		
		//Mutex unlock
		pthread_mutex_unlock(&(shm->var));
		//Unlock semphore
		sem_post(&(shm->empty));
		sleep(2);
	}
	return 0;
}


