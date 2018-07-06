#include "avl.hpp"

NODE::NODE(int data) {
    this->key = data;
    h = 0;
    left = right = NULL;
}

AvlTree::AvlTree() {
    root = NULL;
    constructTime = 0;
    numElements = 0;
}

int AvlTree::height(NODE *&r) {
    if(!r) return -1;
    return r->h;
}

NODE* AvlTree::rightRotation(NODE *&r) {
    NODE *aux;
    aux = r->left;
    r->left = aux->right;
    aux->right = r;
    r->h = std::max(height(r->right),height(r->left)) + 1;
    aux->h = std::max(height(aux->left),r->h) + 1;
    return aux;
}

NODE* AvlTree::leftRotation(NODE *&r) {
    NODE *aux;
    aux = r->right;
    r->right = aux->left;
    aux->left = r;
    r->h = std::max(height(r->right),height(r->left)) + 1;
    aux->h = std::max(height(aux->right),r->h) + 1;
    return aux;
}

NODE* AvlTree::leftRightRotation(NODE *&r) {
    r->left = leftRotation(r->left);
    return rightRotation(r);
}

NODE* AvlTree::rightLeftRotation(NODE *&r) {
    r->right = rightRotation(r->right);
    return leftRotation(r);
}

NODE* AvlTree::insert(NODE *&r, int key) {

    if(!r) {
        NODE *node = new NODE(key);
        return node;
    };
    if(key < r->key){
        r->left = insert(r->left, key);
        if(height(r->left) - height(r->right) == 2){
            if (key < r->left->key){
                r = rightRotation(r);
            } else{
                r = leftRightRotation(r);
            }
        }
    }else
    if( key > r->key) {
        r->right = insert(r->right, key);
        if (height(r->right) - height(r->left) == 2){
            if (key > r->right->key){
                r = leftRotation(r);
            } else{
                r = rightLeftRotation(r);
            }
        }
    }
    r->h = std::max(height(r->left), height(r->right))+1;


    return r;
}

void AvlTree::insertValue(int n) {
    clock_t start = clock();
    root = insert(root, n);
    clock_t end = clock();
    double insertTime = ((double) (end - start))/CLOCKS_PER_SEC;
    constructTime += insertTime;
    numElements ++;
    numElements =+ numElements;
}

void AvlTree::printTree() {
    printTree(root);
}

void AvlTree::printTree(NODE *&r) {
    if(r != NULL){
        printf("%d", r->key);
        printf("(");
        printTree (r->left);
        printTree (r->right);
        printf(")");
    }
}

NODE* AvlTree::getRoot() {
    return root;
}

int AvlTree::getNumElements() {
    return numElements;
}

double AvlTree::getTime() {
    return constructTime;
}