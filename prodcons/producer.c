#include"structure.h"
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<semaphore.h>
#define N 100
int main()
{
	int key=1111;
	int shmid;
	char *ptr;
	struct buffer *shm;
	int i, n=1;
	// Creates shared memory segment and returns segment id on success
	if((shmid=shmget(key, 10, IPC_CREAT))==-1)
	{
		perror("shmget");
		exit(1);
	}
	// Attaches segment to process address space.
	if((ptr=shmat(shmid, NULL, 1))==(char *) -1)
	{
		perror("shmat");
		exit(1);
	}
	
	shm = (struct buffer*) ptr;
	//Initializing the structure
	sem_init(&(shm->empty), 1, N );
	sem_init(&(shm->full), 1, 0);
	pthread_mutex_init(&(shm->var), NULL);
	shm->data[0]=1;

	printf("\n Producer produces: %d", shm->data[0]);
	while(1)
	{
		i=rand()%N;
		//locks semphore
		sem_wait(&(shm->empty));
		//mutex lock
		pthread_mutex_lock(&(shm->var));
		
		shm->data[n]=i;
		printf("\n Producer produces: %d", shm->data[n]);
		n++;
		//unlock mutex
		pthread_mutex_unlock(&(shm->var));
		//unlock semphore
		sem_post(&(shm->full));

		sleep(1);
	}				
	return 0;
}
