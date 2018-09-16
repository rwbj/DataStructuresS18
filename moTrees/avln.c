/*
*/


#include<stdio.h>
#include<stdlib.h>
 
typedef struct node {
	int key;
	struct node *l, *r;
	int height;
} Avln;
 
Avln *root = (Avln *) 0;
 

int max(a,b)
int a,b;
{
	return (a>b?a:b);
}


int height(n)
Avln *n;
{
	if (!n) return 0;
	int temp1, temp2;
	temp1 = height(n->r,h);
	temp2 = height(n->l,h);
	n->height = max(temp1,temp2);
	n->height++;
	return n->height;
}


struct node *rot_right(y)
Avln *y;
{
}

 
Avln *rot_left(x)
Avln *x;
{
}
 


int getBalance(n)
Avln *n;
{
}


 
Avln *add(Avln *node, Avln *n){
	if (!node){
		node = n;
		return node;
	}
	if (node->key < n->key){
		if (!node->l){
			Avln *n = calloc(1,sizeof(Avln));
			n->key = key;
			node->l = n;
			return node;
		}
		add(node->l,key);
	}
	else{
		if (!node->r){
			Avln *n = calloc(1,sizeof(Avln));
			n
		}
	}
}
 
void preorder(n)
Avln *n;
{
	int i;
	if(!n) return;
	for (i=0; i< (root->height - n->height); i++) printf(" ");
	printf("%d\n", n->key);
	preorder(n->l);
	preorder(n->r);
}
 

main(argc, argv, envp)
int argc;
char **argv, **envp;
{
	char buf[1024];
 

	while (gets(buf)) {
		if ((strncmp(buf, "add", 3)) == 0) {
			Avln *n = calloc(1,sizeof(Avln));
			n->key = atoi(&(buf[4]))
			root = add(root, n);
			printf(">>\n");
  			preorder(root);
		}
		else if ((strncmp(buf, "del", 3)) == 0){
			delete(root, atoi(&(buf[4])));
			printf(">>\n");
  			preorder(root);
		}
	}
}

