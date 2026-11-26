#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int valor; 
    int level;
}dado;
struct _leTre{
    dado *data;
    struct _leTre *right;  
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
    new -> right = NULL;
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
        root->right = createTree(root->right,new);
    }
    if(root->right!=NULL && root ->left!=NULL){
        root ->data ->level = (root->right->data->level > root->left->data->level ?root->right->data->level+1 : root->left->data->level+1 );
    }else{
        if(root->right!=NULL){
            root ->data ->level = root->right->data->level+1;
        }else{
            if(root->left!=NULL)
                root ->data ->level = root->left->data->level+1;
        }
    }
    return root;
}
void printTree(node *aux){
    if(aux==NULL){
        return;
    }
    
    printTree(aux->left);
    printf("%d->", aux -> data -> valor);
    printTree(aux->right);

}void printTreeLe(node *aux){
    if(aux==NULL){
        return;
    }
    
    printTreeLe(aux->left);
    printf("%d->", aux -> data -> level);
    printTreeLe(aux->right);
}
node *buscaTree(node* root,int valor){
    if(root == NULL)
        return NULL;
    if(root->data->valor == valor)
        return root;
    if(root->data->valor >= valor){
        return buscaTree(root->left,valor);
    }
    else{
        return buscaTree(root->right,valor);
    }

}
/* (não presta, mas vou deixar aqui)
 node *insere(node *root, node *new){
    if(root == NULL){
        return new;
    }
    root->right = insere(root->right,new);
    return root;
} */
node *deligth(node *root, int ind){
    if(root == NULL){
        return root;
    } 
    if(root->data->valor < ind){
        root ->right = deligth(root->right,ind);
    }else{
        if(root->data->valor > ind){
            root ->left = deligth(root->left,ind);
        }
    }
    if(root -> data -> valor== ind){
        if(root -> left == NULL){
            node *aux = root -> right;
            free(root -> data);
            free(root);
            return aux;
        }else{
            if(root -> right == NULL){
                node *aux = root -> left;
                free(root -> data);
                free(root);
                return aux;
            }
        }
        node *aux = root ->right;
        for(;aux->left!=NULL;aux = aux->left){}
        root -> data ->valor = aux ->data ->valor;
        root ->right = deligth(root ->right, aux->data->valor);
    }
    int haltleft = (root -> left != NULL ? root->left->data->level : 0);
    int haltright = (root -> right != NULL ? root->right->data->level : 0);
    root ->data ->level = (haltleft > haltright? haltleft : haltright)+1;
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
    printf("\n \n");
    root = deligth(root,20);
    printTree(root);
    printf("\n");
    printTreeLe(root);
    return 0;
}