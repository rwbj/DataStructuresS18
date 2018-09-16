#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


typedef struct hashNode{
    struct hashNode *b1, *b0;
    int key, letter, count, sumCount;
    float freq;
} tree;

typedef struct heapNode{
    int id, val;
    tree *link;
} heap;


/**
 * heap[0].id = last node in heap
 * heap[0].val = maximum heap size
 */
heap *newHeap(int maxSize){
    heap *new = malloc(sizeof(heap)*maxSize+1);
    new[0].id = 0;
    new[0].val = maxSize;
    return new;
}

int prtHeap(heap *h){
    for(int i = 1; i<h[0].id; i++){
        printf("%d\t%c\t%d\t%p\n", i, h[i].id, h[i].val, h[i].link);
    }
}

int reheapChildren(heap *h, int index){
    if ((index*2)+1 > h[0].id) return 0; //no children
    if (index*2 == h[0].id && h[index*2].val < h[index].val){ //single child
        heap temp = h[index];
        h[index] = h[index*2];
        h[index*2] = temp;
        reheapChildren(h,index*2);
    }
    if (h[index*2].val < h[index].val || h[(index*2)+1].val < h[index].val){ //2 children
        heap temp;
        temp = h[index];
        if (h[index*2].val < h[(index*2)+1].val){
            h[index] = h[index*2];
            h[index*2] = temp;
            reheapChildren(h,index*2);
        }
        else {
            h[index] = h[(index*2)+1];
            h[(index*2)+1] = temp;
            reheapChildren(h,(index*2)+1);
        }
    }
    return -1;
}

int reheapParent(heap *h, int index){
    if (index <= 1) return 0;
    if (h[index].val < h[index/2].val){
        heap temp = h[index/2];
        h[index/2] = h[index];
        h[index] = temp;
        reheapParent(h,index/2);
    }
    return -1;
}

/*UNTESTED*/
int reheapAll(heap *h, int index){
    reheapChildren(h,index);
    reheapAll(h, index*2);
    reheapAll(h, (index*2)+1);
}

int heapAdd(heap add, heap *h){
    if (!(h[0].id < h[0].val)) return -1;
    h[0].id++;
    h[h[0].id] = add;
    reheapParent(h,h[0].id);
    //printf("adding: %d  %d\n",h[0].id, h[1].val);
    return 0;
}

heap heapPop(heap *h){
    if (h[0].id < 1) return h[0];
    heap pop = h[1];
    h[1] = h[h[0].id];
    h[0].id--;
    reheapChildren(h,1);
    //printf("popping: %d  %d link: %p\n",h[0].id, h[1].val, pop.link);
    //printf("popping: %d  %d\nnew head: %d  %d\n",pop.id,pop.val, h[1].id, h[1].val);
    //prtHeap(h);
    return pop;
}

heap *sort(heap *h){
    heap *list = malloc(sizeof(heap)*(h[0].id));
    list[0].id = h[0].id;
    for(int i = 1; i<list[0].id; i++){
        list[i] = heapPop(h);
    }
    return list;
}

tree *genHash(heap *h, tree *t){
    heap new;
    if (h[0].id < 2) return t;
    tree *hub = calloc(1,sizeof(tree));
    hub->b1 = heapPop(h).link;
    //printf("hub->b1->letter: %c %d\n", hub->b1->letter, hub->b1->count);
    hub->b0 = heapPop(h).link;
    //printf("hub->b0->letter: %c %d\n", hub->b0->letter, hub->b0->count);
    hub->count = hub->b0->count + hub->b1->count;
    //printf("hub->count: %d\n", hub->count);
    new.id = 0;
    new.val = hub->count;
    new.link = hub;
    heapAdd(new,h);
    //prtHeap(h);
    genHash(h,hub);
}

tree *buildHash(tree *t, int tLength){
    heap *h = newHeap(tLength);
    printf("heap info: %d %d\n",h[0].val,h[0].id);
    for (int i = 0; i<tLength; i++){   
        heap *temp = calloc(1,sizeof(heap));
        temp->link = &t[i];
        temp->val = t[i].count;
        temp->id = t[i].letter;
        heapAdd(*temp,h);
        printf("%d\n",temp->link->letter);
    }
    //prtHeap(h);
    return genHash(h, t);
}

int prtHashTree(tree *t, int *key, int depth, int size){
    int *k = malloc(sizeof(int)*size);
    memcpy(k,key,sizeof(int)*size);
    if(!t) return -1;
    if (!t->b1){
        for (int i = 0; i<32; i++){
            if (k[i]==0 || k[i]==1) printf("%d",k[i]);
        }
        printf(" -> %c\n",t->letter);
        return 1;
    }
    k[depth] = 1;
    prtHashTree(t->b1, k, depth+1, size);
    k[depth] = 0;
    prtHashTree(t->b0, k, depth+1, size);
    //printf("%d -> %c\n",t->b0->key, t->b0->letter);
    free(k);
    return 0;
}

void main(){
    char *fileName = "./input3";
    char buff[1024];
    int alph[256], letterPos, totalLetters = 0, key[32];
    float frequ[26];
    tree hashTree[26], *t;
    heap *h;
    memset(key,-1,sizeof(int)*32);
    memset(alph,0,sizeof(int)*256);
    memset(hashTree, 0, sizeof(tree)*26);
    FILE *f;

    f = fopen(fileName, "r");

    while (fgets(buff,sizeof(buff),f) && !feof(f)){
        for(letterPos = 0; buff[letterPos+1]; letterPos++){
            if (buff[letterPos] >= 'a' && buff[letterPos] <= 'z') {
                //alph[buff[letterPos]]++;
                hashTree[buff[letterPos]-'a'].count++;
                hashTree[buff[letterPos]-'a'].sumCount++;
            }
            //printf("%c %d\n", buff[letterPos], alph[buff[letterPos]]);
        }
        totalLetters += letterPos;
        //printf("%d\t%d\t%c\t%s", totalLetters, letterPos, buff[1], buff);
    }
    for(int i = 'a'; i <= 'z'; i++){
        hashTree[i-'a'].letter = i;
        hashTree[i-'a'].freq = ((float)hashTree[i-'a'].count)/((float)totalLetters); //unused
        printf("%c\t%d\t%f\n", hashTree[i-'a'].letter, hashTree[i-'a'].count, hashTree[i-'a'].freq);
    }
    t = buildHash(hashTree, sizeof(hashTree)/sizeof(tree));
    prtHashTree(t, key, 0, sizeof(key)/sizeof(int));
    printf("finished\n");
}