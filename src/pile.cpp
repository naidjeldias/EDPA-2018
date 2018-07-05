#include "pile.hpp"

Pile::Pile() {
    top = NULL;
    size = 0;
}

node::node(int data){
    this->key = data;
    next = NULL;
}

int Pile::getSize() {
    return size;
}

node* Pile::insertValeu(node *&last, int n) {
    node *nwNode = new node(n);
    nwNode->next = last;
    size++;
    return nwNode;
}

void Pile::push(int n) {
    top = insertValeu(top,n);
}

void Pile::removeValeu(node *&last) {
    if(last->next != NULL){
        node *tmp;
        tmp = top->next;
        top = tmp;
    }

}

int Pile::pop() {
    int tmp;
    tmp = top->key;
    removeValeu(top);
    size--;
    return tmp;
}
