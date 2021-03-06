/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "port.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/rpc.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

out * getports_1(in *p1, CLIENT *clnt){
	
	out *output_struct;
	int i, sockfd;
	struct hostent *he;
	struct sockaddr_in sd;

	output_struct=(out*)malloc(sizeof(out));
	if(he=gethostbyname(p1->host)==NULL)
	{
		printf("/n Unable to resolve hostname");
		exit(0);
	}	
	printf("\n Port number \t status");	
	for(i=p1->start; i<=p1->end; i++)
	{
		if((sockfd=socket(AF_INET, SOCK_STREAM, 0))==-1)
		{
			printf("\n Could not create socket");
			exit(1);	
		}
		sd.sin_family=AF_INET;
		sd.sin_port=htons(host);
		sd.sin_addr=*((struct in_addr*)he->h_addr)
	}
	
}
out *getports_1_svc(in *argp, struct svc_req *rqstp)
{
	CLIENT *client;
	return(getports_1(argp, client));
}
