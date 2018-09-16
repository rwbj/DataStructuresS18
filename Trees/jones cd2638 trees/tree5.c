#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct node {
	char *name;
	struct node *left;
	struct node *right;
} treenode;




inorder(t)
treenode *t;
{
  if(!t) return 0;
  inorder(t->left);
  printf("%s\n",t->name);
  inorder(t->right);
}



addNode(n,v)
treenode **n;
char *v;
{
  if(!(*n)){//is tree head?
    treenode *nxt;
    nxt = malloc(sizeof(treenode));
    memset(nxt, 0, sizeof(treenode));
    nxt->name = v; /* safe - caller creates new storage for each */
    *n = nxt;
    printf("hello\n");
    return;
  }

  int test = strcmp(v,(*n)->name);

  if(test < 0){//left
    if(!((*n)->left)){
      treenode *nxt;
      nxt = malloc(sizeof(treenode));
      memset(nxt, 0, sizeof(treenode));
      nxt->name = v; /* safe - caller creates new storage for each */
      (*n)->left = nxt;
      return;
    }
    else addNode(&((*n)->left),v);
  }

  else{ //right
    if(!((*n)->right)){
      treenode *nxt;
      nxt = malloc(sizeof(treenode));
      memset(nxt, 0, sizeof(treenode));
      nxt->name = v; /* safe - caller creates new storage for each */
      (*n)->right = nxt;
      return;
    }
    else addNode(&((*n)->right),v);
  }
}
  

main (argc, argv, envp)
int argc;
char **argv, **envp;
{

/* 

prompt the user for a series of names and add them
in the order given to create a complete binary search tree


the user enters
  giselle
  magda
  aviva
  ahnk
  havi
  minna
  monique


you build:
         giselle
         /     \
      aviva    magda
      /        /   \
    ahnk     havi  minna
                     \
                    monique

then print it out inorder
*/

	treenode *t = 0;
  //t->name = "\0";
	char buf[1024];

	while (gets(buf))
		addNode(&t, strdup(buf));

	inorder(t);
}
