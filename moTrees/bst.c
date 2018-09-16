#include<stdlib.h>
#include<stdio.h>
#include <string.h>

typedef struct anode {
	char *name;
	struct anode *r, *l;
} node;



int contains(node **tree, char *q)
{
	if(!(*tree)) return 0;

	if ( strcmp((*tree)->name, q) == 0) printf("yes\n");
	contains(&(*tree)->l, q);
	contains(&(*tree)->r, q);
}

/*node *findNode(node **tree, node *fnd){
    if(!(*tree))return;
    if (strcmp(fnd->name, (*tree)->name) == 0)
    else if (strcmp(fnd->name, (*tree)->name) < 0){//name > tree

    }
    else if (strcmp(fnd->name, (*tree)->name) > 0{//name < tree

    }
}*/

int delete(node **tree, node *del/*, node *prnt*/){
    /*is in tree?*/
    if(!(*tree))return 0;//node not in tree
	int comp = strcmp(del->name, (*tree)->name);
    if(comp == 0){//found

        if (!(*tree)->l || !(*tree)->r){ //at least one nil node
			if ((*tree)->l) tree = &((*tree)->l); //has one child
			else if ((*tree)->r) tree = &((*tree)->r); //has no child
			else tree = NULL;
			free(tree);
			return 1;
		}
		node *temp;
		temp = (*tree)->r; //2 childs
		while(temp->l){
			temp = temp->l;
		}
		(*tree)->name = temp->name;
    }
    else if (comp < 0){//name > tree
        delete(&(*tree)->l, del/*, &(*tree)*/);
    }
    else /*if (comp > 0*/{//name < tree
        delete(&(*tree)->r, del/*, &(*tree)*/);
    }
}



int insert(node **tree, node *item)
{
	if(!(*tree)) {
		*tree = item;
		return 0;
	}

	if(strcmp(item->name, (*tree)->name) < 0)//if tree > item
		insert(&(*tree)->l, item);

	else 
		if(strcmp(item->name, (*tree)->name) > 0)
			insert(&(*tree)->r, item);
}


void printTree(node *tree)
{
	if (! tree) return;
	printTree(tree->l);
	printf("%s\n",tree->name);
	printTree(tree->r);
}


/* 
The loop below reads from stdin until EOF, then searches
to see if the BST contains the word found in argv[1].

Modify the loop to read a series of lines of one of two types:

i value
d value

Lines starting with the ASCII i are to be inserted into the binary search tree.
Those beginning with 'd' are to be deleted if they exist. If they do not exist,
output a line of text  saying so and do nothing else.

Stop your read loop at EOF (like it is now). Instead of 
calling contains(), print out the tree; make it a preorder print
*/



void main(argc, argv, envp)
int argc;
char **argv, **envp;
{
	int i;
	char buf[1024];
	node *curr, *root;
	root = 0;

	while (gets(buf)) {
		if (buf[0]=='i'){
			curr = (node *)malloc(sizeof(node));
			curr->l = curr->r = NULL;
			curr->name = strdup(&(buf[2]));
			printf("insert: %s\n", &buf[2]);
			insert(&root, curr);
		}else{
			printf("deleting %s\n", &buf[2]);
			delete(&root,curr);
		}
	}


	contains(&root, argv[1]);
}
