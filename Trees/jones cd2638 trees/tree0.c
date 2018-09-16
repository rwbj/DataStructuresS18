#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct node {
	int id;
	struct node *left;
	struct node *right;
} treenode;


main (argc, argv, envp)
int argc;
char **argv, **envp;
{

      treenode *n1, *n2, *n3, *n4, *n5;

	//treenode *n;

      n1 = calloc(1,sizeof(treenode));
      n2 = calloc(1,sizeof(treenode));
      n3 = calloc(1,sizeof(treenode));
      n4 = calloc(1,sizeof(treenode));
      n5 = calloc(1,sizeof(treenode));
      n1->id = 'a';
      n1->id = 'b';
      n1->id = 'c';
      n1->id = 'd';
      n1->id = 'z';
      n1->left = n2;
      n1->right = n3;
      n3->left = n4;
      n3->right = n5;


/* manually create nodes to build this tree:

      a
    /   \
   b    c
       / \
      d  z

*/
}
