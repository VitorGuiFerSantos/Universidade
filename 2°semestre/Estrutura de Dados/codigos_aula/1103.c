#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#define MAX_HEAP 128
typedef struct _hp{
    int heapMin[MAX_HEAP];
    int size;
}Heap;
int parent(int i){
    return (i - 1) / 2;
}
int leftSon(int i){
    return i*2 + 1;
}
int rightSon(int i){
    return i*2 + 2;
}
int min(int a, int b){
    return a < b ? a : b;

}
void addHeapMin(Heap *hMin,int new){
    hMin->heapMin[hMin->size] = new;
    int lastElement = hMin -> size;
    hMin->size++;
    if(hMin -> size == 1){
        return;
    }
    while(hMin -> heapMin[parent(lastElement)] > hMin -> heapMin[lastElement]){
        int aux = hMin -> heapMin[parent(lastElement)];
        hMin -> heapMin[parent(lastElement)] = hMin -> heapMin[lastElement];
        hMin -> heapMin[lastElement] = aux;
        lastElement = parent(lastElement);
    }
}
int deleteHeapMin(Heap* h){
    if(h -> size == 0){
        return -1;
    }
    int removed = h -> heapMin[0];
    h -> heapMin[0] = h -> heapMin[h -> size -1];
    if(h -> size <= 1){
        h -> size--;
        return removed;
    }
    h -> size--;
    int atual = 0;
    while (atual < h -> size){
        int right = rightSon(atual), left = leftSon(atual);
        int aux, menor;
        aux = h -> heapMin[atual];
        if(right < h -> size){
            menor = min(h -> heapMin[right],h -> heapMin[left]);
        }else{
            if( left < h -> size && h -> heapMin[atual] > h -> heapMin[left]){
                h -> heapMin[atual] = h -> heapMin[left];
                h -> heapMin[left] = aux;
            }
            return removed;
        }
        if(h -> heapMin[left] == menor && menor < aux){
            h -> heapMin[atual] = h -> heapMin[left];
            atual = left;
            h -> heapMin[atual] = aux;
        }else{
            if(menor < aux){
                h -> heapMin[atual] = h -> heapMin[right];
                atual = right;
                h -> heapMin[atual] = aux;
            }else{
                return removed;
            }
        }
    }
    
    return removed;
}
void printHeap(Heap *h ){
    int i;
    printf( "-----------------------------------------\n");
    for( i = 0; i < h->size; i++){
        printf( " |%d|",h ->heapMin[i]);
    }
    printf("\n");
    for( i = 0; i < h -> size; i++ ){
        printf(" |%d|",i);
    }
    printf("\n----------------------------------------------------------\n");


}
int main(){
    Heap* hMin = malloc( sizeof( Heap));
    hMin -> size = 0;
    usleep(500000);
    addHeapMin(hMin,10);
    printHeap(hMin);
    usleep(500000);
    addHeapMin(hMin,15);
    printHeap(hMin);
    addHeapMin(hMin,20);
    printHeap(hMin);
    int x = deleteHeapMin(hMin);
    printHeap(hMin);
    return 0;
}

