#include<stdlib.h>
#include<stdio.h>
#include <string.h>

char *dict[200000];
int nf=0;

contains(q) 
char *q;
{
	int i;
	for (i=0; i<nf; i++)
		if (strcmp(q, dict[i]) == 0) 
			printf("yes\n");
}



void main(argc, argv, envp)
int argc;
char **argv, **envp;
{
	char buf[1024];

	while (gets(buf))  {
		printf("linear insert: %s\n", buf);
		dict[nf++] = strdup(buf);
	}
	

	contains(argv[1]);
}
