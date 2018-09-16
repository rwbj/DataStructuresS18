#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

printList(l)
struct node *l;
{
	while(l->next!=NULL){
		printf(l->data);
		l=(l->next);
	}
}


main(argc, argv, envp) {
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;

	head = malloc(sizeof(struct node)); // allocate 3 nodes in the heap
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	printList(head);
}
