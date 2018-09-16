#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct node {
	int id;
	struct node *left;
	struct node *right;
} treenode;


/* FILL ME in */
inorder(t)
treenode *t;
{
    if (!t) return;

	preorder(t->left);
	printf("%c\n", t->id);
	preorder(t->right);
}



/* FILL ME in */
postorder(t)
treenode *t;
{
    if (!t) return;

	preorder(t->left);
	preorder(t->right);
	printf("%c\n", t->id);
}



preorder(t)
treenode *t;
{
	if (!t) return;

	printf("%c\n", t->id);
	preorder(t->left);
	preorder(t->right);
}




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
      n2->id = 'b';
      n3->id = 'c';
      n4->id = 'd';
      n5->id = 'z';
      n1->left = n2;
      n1->right = n3;
      n3->left = n4;
      n3->right = n5;

      printf("pre\n");
      preorder(n1);
      printf("\nin\n");
      inorder(n1);
      printf("\npost\n");
      postorder(n1);


/* print out the tree from the first assignment:

      a
    /   \
   b    c
       / \
      d  z

 print the nodes out three times:
    preorder
    inorder
    postorder

you will have to create the inorder() and postorder()
print functions to do this
*/
}
