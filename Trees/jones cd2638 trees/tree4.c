#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*treenode **list;
list = malloc(sizeof(**treenode)*7);*/

typedef struct node {
	int id;
	struct node *left;
	struct node *right;
} treenode;

typedef struct listNode{
	treenode *tn;
	struct listNode *next;
} listnode;

/* FILL ME in */
int breadthFirst(head,end)
listnode *head; listnode *end;
{
	if(!head) return;
	treenode *t = head->tn;
	printf("%c\n",t->id);
	//add t->left & t->right to top of list
	if (t->left) { //ignore nil nodes
		listnode *tempL = calloc(1,sizeof(listnode));
		tempL->tn = t->left;
		end->next = tempL;
		end = end->next;
	}
	if (t->right) {
		listnode *tempR = calloc(1,sizeof(listnode));
		tempR->tn = t->right;
		end->next = tempR;
		end = end->next;
	}
	head = head->next; //pop

	breadthFirst(head,end);
	return;
}

int main (argc, argv, envp)
int argc;
char **argv, **envp;
{
	//treenode *t;

	/* build a tree any way you like with at least 5 nodes */

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

/*
      a
    /   \
   b    c
  /    / \
 e     d  z
        \
         f
*/

	listnode *ln = calloc(1,sizeof(listnode));
	ln->tn = n1;

	/* print it out breadth first */
	breadthFirst(ln,ln);
}
