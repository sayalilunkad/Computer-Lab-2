//server-shm_server.c
//    -- simply creates the string and shared memory portion. 
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<stdlib.h>
#define size     27
main()
{ 
	char c;
	int shmid;
	key_t key;
	char *shm, *s;
	
	key=1234;
	if((shmid=shmget(key, size, IPC_CREAT))<0)
	{
		perror("shmget");
		exit(1);
	}
	
	if((shm=shmat(shmid, NULL, 0)) == (char *) -1)
	{
		perror("shmat");
		exit(1);
	}
	
	s=shm;
	for(c= 'a'; c<= 'z'; c++)
		*s++=c;
	*s=NULL;
	while(*shm !=  '*' )
		sleep(10);
	exit(0);
}
