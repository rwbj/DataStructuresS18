

/*typedef struct d{
    int key;
} data;*/

void quickSort(int *l, int start, int end){
    int higher, lower, pivot, tmp;
    higher = end;
    lower = pivot = start;
    while(higher > lower){
        while(pivot < higher){
            if(l[pivot] < l[higher]){
                tmp = l[pivot];
                l[pivot] = l[higher];
                l[higher] = tmp;
                pivot = higher;
            }
            else higher--;
        }
        while(pivot > lower){
            if(l[pivot] > l[lower]){
                tmp = l[pivot];
                l[pivot] = l[lower];
                l[lower] = tmp;
                pivot = lower;
            }
            else lower++;
        }
    }
    if(pivot!=start) quickSort(l, start, pivot-1);
    if(pivot!=end) quickSort(l, pivot+1, end);
}

void main(int argc, char *argv[]){
    int *list, length;
    if (argc > 0){
        length = atoi(argv[1]);
        if(!length) length = 100;
    }
    else length = 100;
    list = malloc(length*sizeof(int));
    printf("the unsorted list is:\n");
    for (int i = 0; i<length; i++){
        list[i] = rand();
        printf("%d\tat index %d\n", list[i], i);
    }
    quickSort(list, 0, length-1);
    printf("the sorted list is:\n");
    for(int i = 0; i<length; i++){
        printf("%d\tat index %d\n", list[i], i);
    }
}