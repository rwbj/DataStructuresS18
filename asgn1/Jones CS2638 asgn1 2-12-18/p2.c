#include <stdio.h>
#include <string.h>
#include <stdlib.h>


main(argc, argv, envp)
int argc;
char **argv, **envp;
{
	char c1, c2, *p1, *p2;

	c1 = 'a';
	c2 = 'b';
	p1 = &c1;
	p2 = &c2;


	/* ADD THE ASSIGNMENT STATEMENTS SUch that
		the following print statement shows a b */

	printf("%c %c\n", *p1, *p2);
}
