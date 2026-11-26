#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*typedef struct {
    char str;
}dado;
struct _lf{
    dado *data;
    struct _lf *next;
};
typedef struct _lf FIFO;

typedef struct{
    FIFO *first;
    FIFO *last;
}Sentinela;

Sentinela *createWather(){
    Sentinela *new=malloc(sizeof(Sentinela));
    new->first=NULL;
    new->last=NULL;
    return new;
}
FIFO *createFIFO(char str){
    FIFO *new=malloc(sizeof(FIFO));
    dado *newdata=malloc(sizeof(dado));
    newdata->str=str;
    new->data=newdata;
    new->next=NULL;
    return new;
};
void inQueue(Sentinela *warden,FIFO *new){
    if(warden->first==NULL){
        warden->first=new;
        warden->last=new;
        return;
    }
    warden->last->next=new;
    warden->last=new;
}
void deQueue(Sentinela *warden){
    FIFO *aux=warden->first->next;
    if(aux==NULL){
        free(warden->first);
        warden->first=NULL;
        warden->last=NULL;
        return;
    }
    free(warden->first);
    warden->first=aux;
}
void prinFifo(FIFO *aux){
    if(aux==NULL){
        printf("\n");
        return;
    }
    printf("%c",aux->data->str);
    prinFifo(aux->next);
}
int main(){
    Sentinela *warden=createWather();
    inQueue(warden,createFIFO('e'));
    inQueue(warden,createFIFO('s'));
    inQueue(warden,createFIFO('t'));
    inQueue(warden,createFIFO('r'));
    prinFifo(warden->first);
    deQueue(warden);
    prinFifo(warden->first);
    deQueue(warden);
    prinFifo(warden->first);
    deQueue(warden);
    prinFifo(warden->first);
    deQueue(warden);
    getchar();
    prinFifo(warden->first);
    return 0;
}*/
void inQueue(int *first,int *last){
    if(*first==-1){
        first++;
        last++;
        return;
    }
    last++;
}
void deQueue(int *first,int *last){
    if(*first==*last){
        printf("LIST EMPTY");
        return;
    }
    first++;
    
}

int main(){
    int inicio=-1,fim=0;
    char fifo[30];
    inQueue(&inicio,&fim);
    printf("%d %d\n",inicio,fim);
    deQueue(&inicio,&fim);
    printf("%d %d\n",inicio,fim);
    deQueue(&inicio,&fim);
    printf("%d %d\n",inicio,fim);

}