
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct alink {
	char *name;
	struct alink *next;
} Link;





/* PRINT OUT the names in the list, first(head) to last, one per line */
printList(l) 
struct alink *l;
{
	for(;l;l=l->next){
		printf("%s\n",l->name);
	}
}



/* recursively PRINT OUT the names in the list, last(tail) to first, one per line */
rPrintList(l) 
struct alink *l;
{
	struct alink *s;
	s=l;
	if (!s) return;
	rPrintList(s->next);
	printf("%s\n",s->name);
}



/* CREATE A new link with the given name and add it to the head of the list */
insert(n,l)
char *n;
struct alink **l;
{
	Link *nnode;

	nnode = (Link *) malloc(sizeof(struct alink));
	nnode->name = strdup(n);
	nnode->next = *l;
	*l = nnode;
	//l = &nnode;
	
	
	//head = *l;
	
	
}


/* CREATE A new link with the given name and add it to the end of the list */
append(n,l) 
char *n;
struct alink **l;
{
	Link *nnode, *head, *l2;

	nnode = (Link *) malloc(sizeof(struct alink));
	nnode->name = strdup(n);
	nnode->next = 0;
	head = *l;

	if (head) {
		for (l2=head; l2->next; l2=l2->next); /*l2 now pointing at end */
		l2->next = nnode;
	} else
		*l=nnode;
}



main (argc, argv, envp)
int argc;
char **argv, **envp;
{
	struct alink *list, *list2;
	char buf[1024];

	list=list2=0;

	//*
	while (1) {
		printf("enter a name, ('exit' to stop): ");
		gets(buf);
		if (strcmp(buf, "exit") == 0) break;

		insert(buf, &list);
	}


	printf("forward\n");
	printList(list);
	printf("\nbackward\n");
	rPrintList(list);
	//*/

	/* READ A SERIES of strings from stdin, for each make a link and add it to the head of the list */
	while (1) {
		printf("enter a name, ('exit' to stop): ");
		gets(buf);
		if (strcmp(buf, "exit") == 0) break;

		append(buf, &list2);
	}


	printf("\n\nforward\n");
	printList(list2);
	printf("\nbackward\n");
	rPrintList(list2);

}
