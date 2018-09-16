#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* make p a pointer to a pointer to a pointer to a pointer to an int */
/* assign a 3 to it */

main(argc, argv, envp)
int argc;
char **argv, **envp;
{
	int ****p;
	int ***a, **b, *c, d;

	d=3;
	c=&d;
	b=&c;
	a=&b;

	p=&a;


	printf("%d\n", ****p);

}
