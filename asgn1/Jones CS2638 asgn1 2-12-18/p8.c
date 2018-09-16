#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct data {
	char *name;
	int age;
};


swap(d)
struct data *d;
{
	struct data temp;
	/*temp.age=d[0].age;
	temp.name=d[0].name;
	d[0].age=d[1].age;
	d[0].name=d[1].name;
	d[1].age=temp.age;
	d[1].name=temp.name;*/

	temp=d[0];
	d[0]=d[1];
	d[1]=d[0];
}


main(argc, argv, envp)
int argc;
char **argv, **envp;
{
	int i;
	struct data d[2];

	/* CREATE A ROUTINE called swap above (& call it here) which
	   takes an array of struct data and switched the 1st 2 elements */


	d[0].name = strdup("aviva");
	d[0].age=21;

	d[1].name = strdup("monique");
	d[1].age=23;

	for (i=0; i<2; i++)
		printf("%d\n\tname= %s\n\tage= %d\n", i, d[i].name, d[i].age);

	swap(d);

	for (i=0; i<2; i++)
		printf("%d\n\tname= %s\n\tage= %d\n", i, d[i].name, d[i].age);
}
