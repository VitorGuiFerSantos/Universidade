#include <stdio.h>
#include <stdlib.h>
//Lista dupla
struct tld {
    int n;
    struct tld* next,* prev;
};
typedef struct tld Ld;
typedef struct {
    Ld* head;
    Ld* tail;
}Sent;

//Fila
struct tq {
    int n;
    struct tq* next;
};
typedef struct tq Q;
typedef struct {
    Q* head;
    Q* tail;
}Queue;

//Pilha
struct ts {
    int n;
    struct ts* next;
};
typedef struct ts S;
typedef struct{
    S* top;
}Stack;

//create struct list doubly lock
Sent* getDoubly(Stack* outflow){
    Sent* wDoubly = malloc( sizeof( Sent));
    wDoubly -> head = NULL; 
    wDoubly -> tail = NULL; 
    S* aux = outflow -> top;
    for( ; aux != NULL ; aux = aux -> next){
        if(wDoubly -> head == NULL){
            Ld* new = malloc( sizeof( Ld));
            new -> n = aux -> n;
            new -> next = NULL;
            new -> prev = NULL;
            wDoubly -> head = new; 
            wDoubly -> tail = new; 
        }else{
            Ld* new = malloc( sizeof( Ld));
            new -> n = aux -> n;
            new -> next = NULL;
            new -> prev = wDoubly -> tail;
            wDoubly -> tail -> next = new;
            wDoubly -> tail = new;
        }
    }
    return wDoubly;
    
}

//get struct queue for numbers divisible by three
Queue* getThreeDoubly(Sent* doubly){
    Queue* FIFO = malloc( sizeof( Queue));
    FIFO -> head = NULL;
    FIFO -> tail = NULL;
    Ld* aux = doubly -> head;
    for(; aux != NULL; aux = aux ->next){
        if(aux -> n % 3 == 0){
            if(FIFO -> head == NULL){
                Q* new = malloc( sizeof( Q));
                new -> n = aux -> n;
                new -> next = NULL;
                FIFO -> head = new;
                FIFO -> tail = new;
            }else{
                Q* new = malloc( sizeof( Q));
                new -> next = NULL;
                new -> n = aux -> n;
                FIFO -> tail -> next = new;
                FIFO -> tail = new;
            }
        }
    }
    return FIFO;

}