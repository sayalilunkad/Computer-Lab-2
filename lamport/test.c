#include<stdio.h>

main()
{
	int* i;
	(void*)&i=1;
	printf("%d", *i);
}