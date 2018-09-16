#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct rbtreenode{
    char *data;
    struct rbtreenode *left;
    struct rbtreenode *right;
    char color;
} rbt;
/*
int addNode(rbt *n,c){
    c++
    rbt *nxt;
    int red = 0;
    if (c<3) red++;
    if (n->color=='r') red++;
    
    if (red==0) nxt->color = 'r';
    else nxt->color = 'b';
}*/

int *walkTree(rbt *t, int result, int count){
    int cntL, cntR;
    int *temp;
    if(!t || result) return result;
    if(t->color != 'b' && t->color != 'r') { //has no color
        printf("error 1 at %s\n",t->data);
        return 1;
    }
    /*if (t->color == 'r'){ //red with red child
        rbt *lc = t->left;
        rbt *rc = t->right;
        if ( lc->color == 'r' || rc->color == 'r') {
            printf("error 4 at %s\n",t->data);
            return 4;
        }
    }*/
    if (t->color =='b') count++;
    temp = walkTree(t->left, result, count);
    cntL = temp[1];
    temp = walkTree(t->right, result, count);
    if (temp[1] != cntL);
    return temp;
}

int isRBT(rbt *t){
    if (!t) return -1;
    if (t->color=='r') {
        printf("error 2 at %s\n",t->data);
        return 2; //root is red
    }
    if ((t->left)->color == 'r' || (t->right)->color == 'r') {
        printf("error 3 at %s\n",t->data);
        return 3; //leafs are red
    }
    return walkTree(t,0,0)[0];
}

int countBlack(rbt *t, int count){
    if (t->color =='b') return count++;
    int tempR, tempL;
    tempL = countBlack(t->left, count);
    tempR = countBlack(t->right, count);
    if (tempL==tempR){
        return tempL;
    }
    else return -1;
}

int main(){
    rbt *n1, *n2, *n3, *n4, *n5, *n6, *n7;

	n1 = calloc(1,sizeof(rbt));
	n2 = calloc(1,sizeof(rbt));
	n3 = calloc(1,sizeof(rbt));
	n4 = calloc(1,sizeof(rbt));
	n5 = calloc(1,sizeof(rbt));
	n6 = calloc(1,sizeof(rbt));
	n7 = calloc(1,sizeof(rbt));
	n1->data = "aaa"; n1->color = 'b';
	n2->data = "bbb"; n2->color = 'b';
	n3->data = "ccc"; n3->color = 'b';
	n4->data = "ddd"; n4->color = 'r';
	n5->data = "eee"; n5->color = 'r';
	n6->data = "fff"; n6->color = 'r';
	n7->data = "ggg"; n7->color = 'r';
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
 e     d  g
        \
         f
*/
printf("the tree returned %d\n", isRBT(n1));

/*
    •	Write a function which:
        •	Takes a pointer to a Node as the only incoming argument
        •	Verifies whether or not the tree rooted at Node is a valid red-black tree
        •	Returns a zero if it is a valid red-black tree
        •	Returns an integer > 0 if it is not a valid red-black tree as follows:

            o	Return 1 - one or more nodes are neither red nor black
            o	Return 2 – the root node is red
            o	Return 3 – one or more leaves are red
            o	Return 4 – one or more red nodes does not have two black children
            o	Return 5 – all paths from root to leaf do not contain the same number of black nodes

*/
}