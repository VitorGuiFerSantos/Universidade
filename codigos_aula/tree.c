#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int valor; 
}dado;
struct _leTre{
    dado *data;
    struct _leTre *rigth;  
    struct _leTre *left;  
};
typedef struct _leTre raiTree;
raiTree *createElemnt(int valor){
    raiTree *new = malloc( sizeof( raiTree));
    dado *newdata = malloc( sizeof( dado));
    newdata -> valor = valor;
    new -> data = newdata;
    new -> left = NULL;
    new -> rigth = NULL;
    return new;
}
typedef struct{
    raiTree *father;
}sentinela;

sentinela *createWarden(){
    sentinela *warden = malloc( sizeof( sentinela));
    warden -> father = NULL; 
    return warden;
}
void insirtElemnt(sentinela *warden, raiTree *aux, raiTree *new){
    if(aux == NULL){
        if(warden -> father == NULL){
            warden ->father = new;
            return;
        }
        aux = new;
        return;
    }

    if(aux -> data -> valor < new -> data -> valor){
        if(aux -> rigth != NULL){
            insirtElemnt(warden, aux -> rigth, new);}
        else
           { aux ->rigth = new;}
        return;
    }
    else{
        if(aux -> left != NULL){
            insirtElemnt(warden, aux -> left, new);}
        else{
            aux ->left = new;}
            return;   
    }
}
void printTree(raiTree *aux){
    if(aux==NULL){
        return;
    }
    
    printTree(aux->left);
    printf(" %d ", aux -> data -> valor);
    printTree(aux->rigth);
}
int main(){
    sentinela *warden = createWarden();
    insirtElemnt(warden,warden -> father, createElemnt(5));
    insirtElemnt(warden,warden -> father, createElemnt(3));
    insirtElemnt(warden,warden -> father, createElemnt(8));
    insirtElemnt(warden,warden -> father, createElemnt(9));
    insirtElemnt(warden,warden -> father, createElemnt(1));
    printTree(warden -> father);
    return 0;
}

