#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/**
 * This min heap has only been tested with heap arrays that have 
 * been construced using the heapAdd() function.
 * Using an unsorted array has not been tested
 */

typedef struct heapNode{
    int id;
    int val;
} heap;

int maxHeapSize = 256;

int prtHeap(heap *h){
    for(int i = 1; i<h[0].id; i++){
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

int heapAdd(heap *h, heap add){
    if (!(h[0].id < maxHeapSize)) return -1;
    h[0].id++;
    h[h[0].id] = add;
    reheapParent(h,h[0].id);
    return 0;
}

heap heapPop(heap *h){
    if (h[0].id < 1) return h[0];
    heap pop = h[1];
    h[1] = h[h[0].id];
    h[0].id--;
    reheapChildren(h,1);
    printf("popping: %d  %d\nnew head: %d  %d\n",pop.id,pop.val, h[1].id, h[1].val);
    prtHeap(h);
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
    heap minHeap[maxHeapSize];
    srand((unsigned int)time(NULL));
    minHeap[0].id = 0; //size of the inital heap
    for (int i = 0; i<26; i++){
        heap new;
        new.id = i+100;
        new.val = rand();
        int e = heapAdd(minHeap, new);
        if (e) printf("addHeap: %d failed\n", i);
    }
    printf("\n\nhere is the sorted list\n");
    prtHeap(sort(minHeap));
}