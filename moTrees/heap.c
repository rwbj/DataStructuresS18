#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int heapSize = 100;

typedef struct node{
    int id;
    int val;
} heap;


int prtHeap(heap *h){
    for(int i = 1; i<h[0].id+1; i++){
        printf("%d\t%d\t%d\n", i, h[i].id, h[i].val);
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
        //memcpy(temp,h[index],sizeof(heap));
        temp = h[index];
        if (h[index*2].val < h[(index*2)+1].val){
            //memcpy(h[index],h[index*2],sizeof(heap));
            //memcpy(h[index*2],temp,sizeof(heap));
            h[index] = h[index*2];
            h[index*2] = temp;
            reheapChildren(h,index*2);
        }
        else {
            //memcpy(h[index],h[(index*2)+1],sizeof(heap));
            //memcpy(h[(index*2)+1],temp,sizeof(heap));
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

/*int reheapAll(heap *h){
    for(int i = h[0].id; i>0; i--){
        reheapParent(h,i);
        reheapChildren(h,i);
    }
}*/

int heapAdd(heap *h, heap add){
    if (!(h[0].id < heapSize)) return -1;
    h[0].id++;
    h[h[0].id] = add;
    reheapParent(h,h[0].id);
    return 0;
}

heap heapPop(heap *h){
    if (h[0].id < 1) return h[0];
    prtHeap(h); //printf("\n");
    heap pop = h[1];
    h[1] = h[h[0].id];
    h[0].id--;
    printf("popping: %d  %d\nnew head: %d  %d\n",pop.id,pop.val, h[1].id, h[1].val);
    reheapChildren(h,1);
    prtHeap(h);
    printf("popping: %d  %d\nnew head: %d  %d\n",pop.id,pop.val, h[1].id, h[1].val);
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

int main(){
    heap alph[heapSize];
    srand((unsigned int)time(NULL));
    //printf("%d", sizeof(alph)/sizeof(heap));
    alph[0].id = 0; //size of the inital heap
    for (int i = 0; i<26; i++){
        heap new;
        //alph[i+1].id = i+100;
        //alph[i+1].val = rand();
        new.id = i+100;
        new.val = rand();
        int e = heapAdd(alph, new);
        if (e) printf("addHeap: %d failed\n", i);
        
        //printf("%d %d\n",alph[i+1].id,alph[i+1].val);
    }

    heap new;
    new.id = 200;
    new.val = 20000;
    //printf("%d %d\n",new.id,new.val);
    heapAdd(alph,new);
    //prtHeap(alph);

    heapPop(alph);

    printf("\n\nhere is the sorted list\n");
    prtHeap(sort(alph));

    //reheap(alph,1);
    //prtHeap(alph);



}