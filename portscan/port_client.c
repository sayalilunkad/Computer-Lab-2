/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "port.h"


void port_1(char *host)
{
	CLIENT *clnt;
	out  *result_1;
	in  *getports_1_arg;
	int i;
	result_1= (in*)malloc(sizeof(in));

	getports_1_arg->host=host;
	getports_1_args->start=0;
	getports_1_args->end=65536;

#ifndef	DEBUG
	clnt = clnt_create (host, PORT, PORTVER, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
	
#endif	/* DEBUG */

	result_1 = getports_1(&getports_1_arg, clnt);
	if (result_1 == (out *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	printf("\n The Open Ports are:\n");
	for(i=0;i<result_1->total;i++)
	{
		printf("\n%d", result_1->portno[i]);
	}
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	port_1 (host);
exit (0);
}
