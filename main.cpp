#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
    int h;
}NODE;

typedef NODE* POINT;

//exibindo usando percurso pre ordem(raiz - sub esq - sub dir)
void printTree(POINT r){
    if(r != NULL){
        printf("%d", r->key);
        printf("(");
        printTree (r->left);
        printTree (r->right);
        printf(")");
    }
}


POINT createNode(int key){

    POINT nwNode = (POINT) malloc(sizeof(NODE));

    nwNode->left  = NULL;
    nwNode->right = NULL;

    nwNode->key = key;
    nwNode->h   = 0;
    return nwNode;
}

int height (POINT r){
    if(!r) return -1;
    return r->h;
}

POINT rightRotation(POINT r){

    POINT aux;
    aux = r->left;
    r->left = aux->right;
    aux->right = r;

    r->h = std::max(height(r->right),height(r->left)) + 1;

    aux->h = std::max(height(aux->left),r->h) + 1;

    return aux;

}

POINT leftRotation(POINT r){

    POINT aux;
    aux = r->right;
    r->right = aux->left;
    aux->left = r;

    r->h = std::max(height(r->right),height(r->left)) + 1;

    aux->h = std::max(height(aux->right),r->h) + 1;

    return aux;
}

POINT leftRightRotation(POINT r){
    r->left = leftRotation(r->left);
    return rightRotation(r);
}

POINT rightLeftRotation(POINT r){
    r->right = rightRotation(r->right);
    return leftRotation(r);
}

POINT init(){
    return NULL;
}

POINT insert(POINT r, int key){
    //se a raiz for nula cria o nó e este será a nova arvore
    if(!r) return createNode(key);
    // se a chave for menor, inserir na esquerda
    if(key < r->key){
        r->left = insert(r->left, key);
        //verificando se o nó ficou desbalanceado
        if(height(r->left) - height(r->right) == 2){
            //verificando se o nó foi inserido na sub arvore direita ou esquerda
            //se a chave é menor que a chave do nó a esquerda quer dizer que foi inserido na esquerda, na extremidade,
            // e isso requer uma rotação simples a direita, caso contrário simples a esquerda e depois simples a direita
            if (key < r->left->key){
                r = rightRotation(r);
                printf ("Rotação a direita\n");
            } else{
                r = leftRightRotation(r);
                printf ("Rotação a esquerda e direita\n");
            }
        }
    }else
        if( key > r->key) {
            r->right = insert(r->right, key);
            if (height(r->right) - height(r->left) == 2){
                if (key > r->right->key){
                    r = leftRotation(r);
                    printf ("Rotação a esquerda\n");
                } else{
                    r = rightLeftRotation(r);
                    printf ("Rotação a direita e esquerda\n");
                }
            }
    }
    r->h = std::max(height(r->left), height(r->right))+1;


    return r;
}


int main() {
    int key = 0 ;
    int count = 1;

    POINT root = init();

    printf ("Insira os elementos da arvore e -1 para terminar a inserção\n");
    while (key != -1){
        printf ("\nInsira o elemento %d da arvore ou -1 para terminar a inserção",count);
        scanf("%d",&key);
        if(key != -1){
            root = insert(root,key);
            printTree(root);
        }else{
            printf ("Inserção terminada\n");
        }
        count++;
    }
    printf ("Imprimindo arvore...\n");
    printTree(root);

    return 0;
}