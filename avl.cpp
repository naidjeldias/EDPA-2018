#include "avl.hpp"


//typedef struct node POINT;


//exibindo usando percurso pre ordem(raiz - sub esq - sub dir)
void Avl::printTree(POINT r) {
    if(r != NULL){
        printf("%d", r->key);
        printf("(");
        printTree (r->left);
        printTree (r->right);
        printf(")");
    }
}

Avl::POINT Avl::createNode(int key) {
    POINT nwNode = (POINT) malloc(sizeof(NODE));

    nwNode->left  = NULL;
    nwNode->right = NULL;

    nwNode->key = key;
    nwNode->h   = 0;
    return nwNode;
}



int Avl::height(POINT r) {
    if(!r) return -1;
    return r->h;
}

Avl::POINT Avl::rightRotation(POINT r) {
    POINT aux;
    aux = r->left;
    r->left = aux->right;
    aux->right = r;

    r->h = std::max(height(r->right),height(r->left)) + 1;

    aux->h = std::max(height(aux->left),r->h) + 1;

    return aux;
}

Avl::POINT Avl::leftRotation(POINT r) {
    POINT aux;
    aux = r->right;
    r->right = aux->left;
    aux->left = r;

    r->h = std::max(height(r->right),height(r->left)) + 1;

    aux->h = std::max(height(aux->right),r->h) + 1;

    return aux;
}

Avl::POINT Avl::leftRightRotation(POINT r) {
    r->left = leftRotation(r->left);
    return rightRotation(r);
}

Avl::POINT Avl::rightLeftRotation(POINT r) {
    r->right = rightRotation(r->right);
    return leftRotation(r);
}

void Avl::initTree() {
    rootAvl = NULL;
}

Avl::POINT Avl::getRootAvl() {
    return rootAvl;
}

Avl::POINT Avl::insert(POINT r, int key) {
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