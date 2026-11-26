#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 50
typedef struct {
    int idade;
    char name[MAX_NAME];
}dado;

struct _le{
    dado *data;
    struct _le *next;

};
typedef struct _le listElement;

typedef struct{
    listElement *first;
    listElement *last;
}sentinela;

sentinela *criasentila(){
    sentinela *novo_endereco;
    novo_endereco=malloc(sizeof(sentinela));
    novo_endereco->first=NULL;
    novo_endereco->last=NULL;
    return novo_endereco;
};
listElement *createElement(int valor,char name[]){
    listElement*new =(listElement *) malloc(sizeof(listElement));
    dado  *newdata=(dado *)malloc(sizeof(dado));

    newdata->idade=valor;
    strcpy(newdata->name , name);
    
    new -> data = newdata;
    new -> next = NULL;

    return new;
}
listElement *inserElemnt(sentinela *fulano,int valor,char name[]){
    listElement *new=(createElement(valor,name));
    if (fulano->first == NULL) {
        fulano->first = new;
        fulano->last = new;
        return new;
    }
    fulano->last->next=new;


    return new;
}
void printList(sentinela *wdog){
    listElement *aux;

    printf("\n----------------------- My List S2 -----------------\n");

        for (aux = wdog->first; aux != NULL; aux = aux->next){
            printf("\t -> id: %d, name: %s\n", aux->data->idade, aux->data->name);
        }
    printf("----------------------------------------------------\n");


}
int main(){
    sentinela *guarda;
    guarda = criasentila();
    listElement *elemento;
    elemento = createElement(15, "scooby");
    guarda -> first= elemento;
    guarda ->last = elemento; 
    guarda ->last=inserElemnt(guarda,21, "salsicha");
    guarda->last=inserElemnt(guarda,22, "Velma");
    guarda->last=inserElemnt(guarda,23, "daphine");
    guarda->last=inserElemnt(guarda,24, "fred");
    
    printList(guarda);

    return 0;
}

 