#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct node {
	int id;
	struct node *left;
	struct node *right;
} treenode;




preorder(t)
treenode *t;
{
	if (!t) return;

	printf("%d\n", t->id);
	preorder(t->left);
	preorder(t->right);
}




main (argc, argv, envp)
int argc;
char **argv, **envp;
{

	treenode *n, *n2, *n3;


	n = malloc(sizeof(treenode));
	n2 = malloc(sizeof(treenode));
	n3 = malloc(sizeof(treenode));


	n2->id=2;
	n2->left = 0;
	n2->right = 0;

	n3->id=3;
	n3->left = 0;
	n3->right = 0;


	n->id = 1;
	n->left = n2;
	n->right = n3;
	

	preorder(n);
}
