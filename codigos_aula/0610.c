#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME 50
typedef struct{
    int dia;
    int mes;
    int ano;
}data;
typedef struct {
    int id;
    char name[MAX_NAME];
    double salary;
    data birth;
}funcionario;
struct _le{
    funcionario *dataM;
    struct _le *next;
    struct _le *prev;
};
typedef struct _le listelemnt;
typedef struct{
    listelemnt *first;
    listelemnt *last;
}sentinela;
sentinela *createWather(){
    sentinela *warden=malloc(sizeof(sentinela));
    warden->first=NULL;
    warden->last=NULL;
    return warden;
}
listelemnt *creatElemnt(int id,char name[],double salary,int dia,int mes, int ano){
    listelemnt *new=malloc(sizeof(listelemnt));
    funcionario *newdata=malloc(sizeof(funcionario));
    newdata->id=id;
    strcpy(newdata->name,name);
    newdata->salary=salary;
    newdata->birth.ano=ano;
    newdata->birth.mes=mes;
    newdata->birth.dia=dia;
    new->dataM=newdata;
    new->next=NULL;
    new->prev=NULL;
    return new;
}
void insertElemntOrder(sentinela *warden,listelemnt *new){
    if(warden->first=NULL){
        warden->first=new;
        warden->last=new;
        return;
    }
    listelemnt *aux = warden -> first;
    while (aux!=NULL)
    {
        /* code */
    }
    

}

