#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct{
    int valor; 
    int level;
}dado;
struct _leTre{
    dado *data;
    struct _leTre *rigth;  
    struct _leTre *left;  
};
typedef struct _leTre node;

node *createElemnt(int valor){
    node *new = malloc( sizeof( node));
    dado *newdata = malloc( sizeof( dado));
    newdata -> valor = valor;
    newdata -> level = 1;
    new -> data = newdata;
    new -> left = NULL;
    new -> rigth = NULL;
    return new;
}
node *createTree(node *root, node *new){
    if(root == NULL){
        return new;
    }
    if(root->data->valor >= new->data->valor){
        root->left = createTree(root->left,new);
    }
    else{
        root->rigth = createTree(root->rigth,new);
    }
    return root;
}
void printTree(node *aux){
    if(aux==NULL){
        return;
    }
    printTree(aux->left);
    printf("%d->", aux -> data -> valor);
    printTree(aux->rigth);
}
node *deligth(node *root, int ind){
    if(root == NULL){
        return root;
    } 
    if(root->data->valor < ind){
        root ->rigth = deligth(root->rigth,ind);
    }else{
        if(root->data->valor > ind){
            root ->left = deligth(root->left,ind);
        }
    }
    if(root -> data -> valor== ind){
        if(root -> left == NULL){
            node *aux = root -> rigth;
            free(root -> data);
            free(root);
            return aux;
        }else{
            if(root -> rigth == NULL){
                node *aux = root -> left;
                free(root -> data);
                free(root);
                return aux;
            }
        }
        node *aux = root ->rigth;
        for(;aux->left!=NULL;aux = aux->left){}
        root -> data ->valor = aux ->data ->valor;
        root ->rigth = deligth(root ->rigth, aux->data->valor);
    }

    return root;

}
int main(){
    node *root = NULL;
    root = createTree(root,createElemnt(30));
    root = createTree(root,createElemnt(9));
    root = createTree(root,createElemnt(20));
    root = createTree(root,createElemnt(8));
    root = createTree(root,createElemnt(16));
    printTree(root);
    root = deligth(root,30);
    root = deligth(root,8);
    root = deligth(root,20);
    root = deligth(root,9);
    root = deligth(root,16);
    printf("\n \n");
    printTree(root);
    return 0;
}