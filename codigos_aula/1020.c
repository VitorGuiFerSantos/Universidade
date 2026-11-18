#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        root->rigth = createTree(root->rigth,new);
    }
    else{
        root->left = createTree(root->left,new);
    }
    return root;
}
int nodeHeight(node *root){
    if(root == NULL)
        return 0;
    if(root -> left == NULL && root -> rigth == NULL)
        return 1;
    root -> data -> level += nodeHeight(root->left);
    root -> data -> level += nodeHeight(root->rigth);
    return 0;
}

void printTree(node *aux){
    if(aux==NULL){
        return;
    }
    
    printf("%d->", aux -> data -> valor);
    printTree(aux->rigth);
    printTree(aux->left);
}

void printTreeLevel(node *aux){
    if(aux==NULL){
        return;
    }
    
    printf("%d->", aux -> data -> level);
    printTreeLevel(aux->rigth);
    printTreeLevel(aux->left);
}
node *buscaTree(node* root,int valor){
    if(root == NULL){
        return NULL;}
    if(root->data->valor == valor){
        return root;}

    if(root->data->valor >= valor){
        return buscaTree(root->rigth,valor);
    }
    else{
        return buscaTree(root->left,valor);
    }

}
int searchDepth(node *root, int nível){ 
}
int main(){
    node *root = NULL;
    root = createTree(root,createElemnt(30));
    root = createTree(root,createElemnt(9));
    root = createTree(root,createElemnt(20));
    root = createTree(root,createElemnt(8));
    root = createTree(root,createElemnt(16));
    nodeHeight(root);
    printTree(root);
    printf("\n ar \n");
    printTreeLevel(root);
    printf("\n lv \n");

    node *search = buscaTree(root,1);
    printf("%d \n", search != NULL ? search->data->valor : 0);
    return 0;
}

