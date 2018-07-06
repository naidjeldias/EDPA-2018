#include <iostream>
#include <stdio.h>
#include <stdlib.h>



struct node{
    int key;
    struct node *next;
    explicit node(int);
};


class Pile{

private:
    node *top;
    int size;

protected:
    node* insertValeu(node *&, int);
    void removeValeu(node *&);

public:
    Pile();
    int getSize();
    void push(int);
    int pop();


};