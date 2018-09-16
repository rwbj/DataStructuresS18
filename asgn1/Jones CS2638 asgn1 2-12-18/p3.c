#include <stdio.h>
#include <string.h>
#include <stdlib.h>


main(argc, argv, envp)
int argc;
char **argv, **envp;
{
	char *str;
	str = malloc(sizeof(char)*4);
	printf("str = %ld\n",str);
	
	for (int i = 0; i<3;i++){
		*(str+i)='a'+i;
	}
	*(str+3)='\0';

	/* allocate space for the string, store "abc" in it */

	printf("%s\n", str);
}
