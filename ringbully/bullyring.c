#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

void ring(int);
void bully(int, int);
struct process{
	int id;
	int pno;
}p[10];


int main()
{
	pid_t pid;
	int n, i,j=0,k, eid, op;
	printf("\nEnter the number of processes:");
	scanf("%d",&n);
	printf("\n Sr.No\tProcess ID");
	for(i=0;i<n;i++)
	{
		pid=fork();
		if(pid)
		{
			p[i].id=pid;
			p[i].pno=i;
			printf("\n %d \t %d", p[i].pno, p[i].id);
			j++;
			continue;
		}
		else
		{
			while(1){}
		}
	}
	printf("\n Coordinator elected is process %d with pid=%d\n", p[n-1].pno, p[n-1].id);
	k=kill(p[n-1].id, SIGCHLD);
	sleep(5);
	if(k==0)
	{
		printf("\nProcess no %d with pid=%d had crashed", p[n-1].pno, p[n-1].id);
	}
	
		printf("\nSelect Election Algorithm:");
		printf("\n1.Ring Algorithm");
		printf("\n2.Bully Algorithm");
		printf("\n3.Exit\n");
		scanf("%d", &op);
		switch(op)
		{
			case 1:
			ring(n);
			break;
			case 2:
			bully(p[n-1].pno, n);
			break;
			case 3:
			break;
		}
}	


void ring(int n)
{
	int rndm, i, j=0, max=0,temp;
	int priority[10];
	rndm=rand()%n;
	printf("\n Process no %d with pid=%d has invoked election\n", p[rndm].pno, p[rndm].id );
	j=rndm;
	for(i=0; j<n-1; j++)
	{
		priority[i]=p[j].id;
		printf("\n Process %d passes message to %d", p[j].id, p[j+1].id);	
		i++;		
	}
	for(j=0; j<i; j++)
	{
		temp=priority[j];
		if(temp<priority[j+1])
		max=priority[j+1];
		else
		max=temp;
	}
	printf("\n New coordinator elected is pid=%d",max);
}


void bully(int no, int n)
{
	int rndm, i, j, count;	
	int isalive[10];
	for(i=0;i<n;i++)
	{
		isalive[i]=1;
	}
	isalive[no]=0;
	rndm=rand()%n;
	printf("\n Process no %d with pid=%d has invoked election\n", p[rndm].pno, p[rndm].id );
	for(j=rndm; j<n; j++)
	{
		if(isalive[j]==1)
		count=j;
	}
	printf("\nThe new coordinator elected id process no %d with pid %d", p[count].pno, p[count].id);
}
		
		
	
