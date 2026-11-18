#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 50
typedef struct{
    int id;
    char name[MAX_NAME];
    double salary;
}dado;
struct _le{
    dado *data;
    struct _le *next;
    struct _le *prev;
};
typedef struct _le listElemnt;
typedef struct{
    listElemnt *first;
    listElemnt *last;
}sentinela;
sentinela *createWather(){
    sentinela *warden=malloc(sizeof(sentinela));
    warden->first=NULL;
    warden->last=NULL;
    return warden;
}
listElemnt *createElemnt(int id,char name[], double salary){
    listElemnt *new=malloc(sizeof(listElemnt));
    dado *newdata=malloc(sizeof(dado));
    newdata->id=id;
    strcpy(newdata->name,name);
    newdata->salary=salary;
    new->data=newdata;
    new->next=NULL;
    new->prev=NULL;
    return new;
}
void insirtElemntOrder(sentinela *warden,listElemnt *new){
    if(warden->first==NULL){
        warden->first=new;
        warden->last=new;
        return;
    }
    listElemnt *aux=warden->first;
    while (aux!=NULL){
        if(strcmp(aux->data->name,new->data->name)>0){
            break;
        }
        aux=aux->next;
    }
    if(aux==NULL){
        warden->last->next=new;
        new->prev=warden->last;
        warden->last=new;
        return;
    }
    new->next=aux;
    if(aux->prev==NULL){
        warden->first->prev=new;
        warden->first=new;
    }
    else{
        new->prev=aux->prev;
        aux->prev->next=new;
        aux->prev=new;
    }
    
}
void delitElemnt(sentinela *Warden, int id){
    listElemnt *aux = Warden->first;

    while(aux != NULL){
        if(aux->data->id == id){

            // Primeiro elemento
            if(aux->prev == NULL){
                Warden->first = aux->next;

                if(Warden->first != NULL)
                    Warden->first->prev = NULL;
                else
                    Warden->last = NULL;
            }

            // Último elemento
            else if(aux->next == NULL){
                Warden->last = aux->prev;
                Warden->last->next = NULL;
            }

            // Elemento do meio
            else{
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
            }

            free(aux->data);
            free(aux);
            return;
        }

        aux = aux->next;
    }
}
void printList(listElemnt *aux){
    if(aux==NULL){
        return;
    }
        printf("\t -> id: %d, name: %s, sal: %.2lf\n", aux->data->id, aux->data->name, aux->data->salary);
    printList(aux->next);
}
void printacontr(listElemnt *aux){
    if(aux==NULL){
        return;
    }
    printf("\t -> id: %d, name: %s, sal: %.2lf\n", aux->data->id, aux->data->name, aux->data->salary);
    printacontr(aux->prev);

}

int main(){
    sentinela *guarda;
    guarda = createWather();
    insirtElemntOrder(guarda, createElemnt(2, "b", 8000.00));
    insirtElemntOrder(guarda, createElemnt(1, "a", 8000.00));
    insirtElemntOrder(guarda, createElemnt(3, "c", 8000.00));
    insirtElemntOrder(guarda, createElemnt(5, "e", 8000.00));
    insirtElemntOrder(guarda, createElemnt(4, "d", 8000.00));
    
    printf("\n----------------------- My List S2 -----------------\n");
    
    printList(guarda->first);
    
    printf("\n----------------------------------------------------\n");



    delitElemnt(guarda,5);

    getchar();

    printf("\n----------------------- My List S2 -----------------\n");
    
    printacontr(guarda->last);
    
    printf("\n----------------------------------------------------\n");
    
    getchar();

    printf("\n----------------------- My List S2 -----------------\n");

    printList(guarda->first);
    
    printf("\n----------------------------------------------------\n");



    return 0;
}