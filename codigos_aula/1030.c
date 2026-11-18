#include <stdio.h>
#include <stdlib.h>
#define SIZE  1024
typedef struct{
    int heap[SIZE];
    int size;
}MAXheap;
int parent(int i){
    return (i-1)/2;
}
int leftSon(int i){
    return i*2+1;
}
int rightSon(int i){
    return i*2+2;
}
int max(int a, int b){
    return a > b ? a : b;
}
void addheap(MAXheap *h, int elmt){
    int i = h->size;
    h->heap[h->size++] = elmt;
    if(h->size==1){
        return;
    }
    if(h->heap[i]< h->heap[parent(i)]){
        return;
    }
    do{
        int aux = h->heap[parent(i)];
        h->heap[parent(i)]= h->heap[i];
        h->heap[i] = aux;
        i = parent(i);
    }while (h->heap[i]> h->heap[parent(i)]);
    
}
void delith(MAXheap *h){
    if(h->size==0){
        return;
    }
    if(h->size==1){
        h->size--;
        return;
    }
    h->size--;
    h->heap[0] = h->heap[h->size];
    int i = 0;
    while (i < h -> size){
        int right = rightSon(i), left = leftSon(i);
        int aux, maior;
        aux = h -> heap[i];
        if( right < h ->size){
            maior = max(h -> heap[left], h -> heap[right]);
        }else{
            if(left < h ->size && h ->heap[i] < h -> heap[left]){
            h -> heap[i] = h -> heap[left];
            h -> heap[left] = aux;}
            return;
        }
        if(h -> heap[left] == maior && maior > aux){
            h -> heap[i] = h ->heap[left];
            i = left;
            h ->heap[i] = aux;
        }else{
            if(h -> heap[right] == maior && maior > aux){
                h -> heap[i] = h ->heap[right];
                i = right;
                h ->heap[i] = aux;
            }else{
                return;
            }
        }
    }
}
void printHeap(MAXheap *he){
    int i;
    printf("\n----------------------------------------------------------\n");
    for( i = 0; i < he -> size; i++ ){
        printf(" |%d|",he->heap[i]);
    }
    printf("\n");
    for( i = 0; i < he -> size; i++ ){
        printf(" |%d|",i);
    }
    printf("\n----------------------------------------------------------\n");
}
int main(){
    MAXheap  *h = malloc(sizeof(MAXheap));
    h->size = 0;
    addheap(h,1);
    printHeap(h);
    addheap(h,2);
    printHeap(h);
    addheap(h,3);
    printHeap(h);
    addheap(h,4);
    printHeap(h);
    addheap(h,5);
    printHeap(h);
    addheap(h,10);
    printHeap(h);
    addheap(h,30);
    printHeap(h);
    addheap(h,50);
    printHeap(h);
    addheap(h,100);
    printHeap(h);
    addheap(h,500);
    printHeap(h);
    addheap(h,580);

    printHeap(h);
    printf("\n\n");
    delith(h);
    printHeap(h);
    return 0;
}