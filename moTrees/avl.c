#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct node {
	int key;
	struct node *l, *r;
	int height;
} Avln;

typedef struct list{
	Avln *path;
	struct list *next;
} stack;
 
Avln *root = (Avln *) 0;

int max(int a, int b){
	return (a>b?a:b);
}

int height(stack *st){
	int m = (max(st->path->r->height, st->path->l->height));
	st->path->height = m+1;
	if (!st->next) return st->path->height;
	height(st->next);
	/*if (!n) return 0;
	int temp1, temp2;
	temp1 = height(n->r,h);
	temp2 = height(n->l,h);
	n->height = max(temp1,temp2);
	n->height++;
	return n->height;*/
}
 

Avln *rot_right(Avln *y)
{
}


Avln *rot_left(Avln *x)
{
}
 


int getBalance(Avln *n)
{
	return (n->r->height - n->l->height);
}

Avln *search(Avln *n, int k){
	if (!n) return NULL;
	if (n->key == k) return n;
	if (n->key < k) search(n->l,k);
	else if (n->key > k) search(n->r,k);
	return NULL;
}
 
stack *add(Avln *node, int key, stack *st){ //builds stack and avl
	stack *top = calloc(1,sizeof(stack));
	top->path = node; //link to passed in node
	top->next = st; //link head of stack
	st = top; //add to head of stack
	if(!node){// node not present
		top->path = calloc(1,sizeof(node));
		top->path->key = key;
		return top->path;
	}
	//continue untill empty link
	if(node->key > key){
		add(node->r,key);
	}
	else{
		add(node->l,key);
	}
}
 
void preorder(Avln *n){
	int i;
	if(!n) return;
	for (i=0; i< (root->height - n->height); i++) printf(" ");
	printf("%d\n", n->key);
	preorder(n->l);
	preorder(n->r);
}
 

main(int argc,char **argv, char **envp){
	char buf[1024];
 

	while (gets(buf)) {
		if ((strncmp(buf, "add", 3)) == 0) {
			root = add(root, atoi(&(buf[4])), st);
			printf(">>\n");
  			preorder(root);
		}
	}
}

