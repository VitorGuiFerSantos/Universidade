  #include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME 50

typedef struct _func
{
    int id;
    char name[MAX_NAME];
    float salary;
} Employer;

//definição do nosso elemento da lista encadeada
struct _le{
    Employer *data;
    struct _le *next;
};
typedef struct _le ListElement;

//Definição do nosso sentinela, elemento que armazena o primeiro
typedef struct _wdog {
    ListElement *first; //head
} WDog;


WDog *createWatcher(){
    WDog *new;
    new = malloc(sizeof(WDog));
    new->first = NULL;
    return new;
}

ListElement *createListElement(int id, char *name, float salary){
    ListElement *new = malloc(sizeof(ListElement));
    // Criando os dados do elemento da lista
    Employer *employer = malloc(sizeof(Employer));
    employer->id = id;
    strcpy(employer->name, name);
    //snprintf(employer->name, MAX_NAME, "%s", name);
    employer->salary = salary;
    //fim criação de dados
    //colocando os dados no elemento dalista
    new->data = employer;
    new->next = NULL;

    return new;
}


void printList(WDog *wdog){
    ListElement *aux;

    printf("\n----------------------- My List S2 -----------------\n");

        for (aux = wdog->first; aux != NULL; aux = aux->next){
            printf("\t -> id: %d, name: %s, sal: %.2f\n", aux->data->id, aux->data->name, aux->data->salary);
        }
    printf("----------------------------------------------------\n");


}

int main(){
    WDog *watcherDog;
    //criamos o sentinela
    watcherDog = createWatcher();
    //criamos o primeiro elemento da lista
    ListElement *element = createListElement(1, "Jão", 8000.00);
    //colocamos o primeiro elemento no first do sentinela.
    watcherDog->first = element;
    element->next = createListElement(1, "Jão", 8000.00);
    element->next = createListElement(1, "Jão", 8000.00);

    printList(watcherDog);


    return 0;
}