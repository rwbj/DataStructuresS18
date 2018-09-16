#include <stdio.h>
#include <string.h>
#include <stdlib.h>



/* FILL THIS In so that is swaps the incoming args */
swap(int *a1, int *b1)
{
	
	int i = *b1;
	*b1 = *a1;
	*a1 = i;

}



main(argc, argv, envp)
int argc;
char **argv, **envp;
{
	int a=3, b=5;

	/* SHOULD PRINT  3 5 */
	printf("a = %d    b= %d\n",a,b);

	swap(&a, &b);

	/* SHOULD PRINT  5 3 */
	printf("a = %d    b= %d\n",a,b);
}