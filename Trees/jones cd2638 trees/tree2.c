#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct node {
	int id;
	struct node *left;
	struct node *right;
} treenode;

//int count = 0;

int countNodes(t,c)
treenode *t; int c;
{
      //printf("node: %s\tcount: %d\n",t->id, c);
	if(!t) return c;
	c++;
	c = countNodes(t->left,c);
	c = countNodes(t->right,c);
      return c;
}


int main (argc, argv, envp)
int argc;
char **argv, **envp;
{
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

      //countNodes(n1);

/*
      a
    /   \
   b    c
  /    / \
 e     d  z
        \
         f
*/
	//treenode t;
	/* build a binary tree with at least 6 nodes */

	printf("the tree has %d nodes\n", countNodes(n1,0));
	//printf("the tree has %d nodes\n", count);
}
