#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct rbtreenode{
    char *data;
    struct rbtreenode *left;
    struct rbtreenode *right;
    char color;
} rbt;

int walkTree(rbt *t, int result, char prnt){
    if(!t || result) {
        return result;
    }
    if(t->color != 'b' && t->color != 'r') { //has no color
        printf("error 1 at %s\n",t->data);
        return 1;
    }
    if (prnt == 'r' && t->color == 'r') return 4;
    result = walkTree(t->left, result, t->color);
    result = walkTree(t->right, result, t->color);
    return result;
}


int countBlack(rbt *t, int count){
    if (!t || count == -1) return count;
    if (t->color =='b') count++;
    int tempR, tempL;
    tempL = countBlack(t->left, count);
    tempR = countBlack(t->right, count);
    printf("help: cl %d, cr %d, cnt %d, id %s\n", tempL, tempR, count, t->data);
    if (tempL==tempR){
        return tempL;
    }
    else {
        printf("error 5 at %s\n", t->data);
        return -1;
    }
}

int isRBT(rbt *t){
    if (!t) return -1;
    if (t->color=='r') {
        printf("error 2 at %s\n",t->data);
        return 2; //root is red
    }
    //if (countBlack(t,0) < 0) return 5; // uneven black
    return walkTree(t,0,t->color);
}

int main(){
    rbt *n12, *n5, *n3, *n4, *n10, *n7, *n6, *n8, *n11, *n15, *n13, *n14, *n17;

	n12 = calloc(1,sizeof(rbt));
	n5 = calloc(1,sizeof(rbt));
	n3 = calloc(1,sizeof(rbt));
	n4 = calloc(1,sizeof(rbt));
	n10 = calloc(1,sizeof(rbt));
	n7 = calloc(1,sizeof(rbt));
    n6 = calloc(1,sizeof(rbt));
	n8 = calloc(1,sizeof(rbt));
    n11 = calloc(1,sizeof(rbt));
    n15 = calloc(1,sizeof(rbt));
    n13 = calloc(1,sizeof(rbt));
    n14 = calloc(1,sizeof(rbt));
    n17 = calloc(1,sizeof(rbt));
	n12->data = "b12"; n12->color = 'b';
	n5->data = "b5"; n5->color = 'b';
	n3->data = "b3"; n3->color = 'b';
	n4->data = "r4"; n4->color = 'r';
	n10->data = "r10"; n10->color = 'r';
	n7->data = "b7"; n7->color = 'b';
	n6->data = "r6"; n6->color = 'r';
    n8->data = "r8"; n8->color = 'r';
	n11->data = "b11"; n11->color = 'b';
    n15->data = "b15"; n15->color = 'b';
    n13->data = "b13"; n13->color = 'b';
    n14->data = "r14"; n14->color = 'r';
    n17->data = "b17"; n17->color = 'b';
    n12->left = n5;
    n12->right = n15;
    n5->left = n3;
    n5->right = n10;
    n3->right = n4;
    n10->left = n7;
    n10->right = n11;
    n7->left = n6;
    n7->right = n8;
    n15->left = n13;
    n15->right = n17;
    n13->right = n14;

    /*
    rbt *n9;
    n9 = calloc(1,sizeof(rbt));
    n9->data = "r9"; n9->color = 'r';
    n8->right = n9;//*/


printf("the tree returned %d\n", isRBT(n12));

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