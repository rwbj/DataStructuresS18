#include <stdio.h>
#include <string.h>
#include <stdlib.h>


main(argc, argv, envp)
int argc;
char **argv, **envp;
{
	char **str;
	/* allocate space for an array of 10 strings.
	   store "aaa", "bbb", "ccc", ... in the 10
	   strings. i.e. str[0] should have "aaa" etc. */


	/* this should print them all out */
	str = malloc(sizeof(char *)*10);
	for (int i=0; i<10; i++){
		*(str+i)=malloc(sizeof(char)*4);
		for(int j=0;j<3;j++){
			*(*(str+i)+j)='a'+i;
		}
		*(*(str+i)+3)=0;

		printf("str[%d] = %s\n", i, *(str+i));
	}

}