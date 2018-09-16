#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct node {
	int id;
	struct node *left;
	struct node *right;
} treenode;



int countLevels(t,c)
treenode *t; int c;
{
	int c1,c2;
	if (!t) return c;
	c++;
	c1 = countLevels(t->left,c);
	c2 = countLevels(t->right,c);
	if (c<c1) c=c1;
	if (c<c2) c=c2;
	return c;	
}




int main (argc, argv, envp)
int argc;
char **argv, **envp;
{

	//treenode *t;
	/* build a binary tree with at least 3 levels */
	treenode *n1, *n2, *n3, *n4, *n5, *n6, *n7;

	n1 = calloc(1,sizeof(treenode));
	n2 = calloc(1,sizeof(treenode));
	n3 = calloc(1,sizeof(treenode));
	n4 = calloc(1,sizeof(treenode));
	n5 = calloc(1,sizeof(treenode));
	n6 = calloc(1,sizeof(treenode));
	n7 = calloc(1,sizeof(treenode));
	n1->id = 'a';
	n2->id = 'b';
	n3->id = 'c';
	n4->id = 'd';
	n5->id = 'e';
	n6->id = 'f';
	n7->id = 'z';
	n1->left = n2;
	n1->right = n3;
	n2->left = n5;
	n3->left = n4;
	n3->right = n7;
	n4->right = n6;
	//n6->right = n2; //return 6
	//n6->right = n7; //return 5

/*
      a
    /   \
   b    c
  /    / \
 e     d  z
        \
         f
*/

	printf("the tree has %d levels\n", countLevels(n1,0));
}
