#include <iostream>
#include <stdio.h>
#include <stdlib.h>

enum Color {RED, BLACK, DOUBLE_BLACK};

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
    int h;
}NODE;

typedef NODE* POINT;

struct Node
{
    int data;
    int color;
    Node *left, *right, *parent;

    explicit Node(int);
};

class RBTree{

private:
    Node *root;

protected:
    void rotateLeft(Node *&);
    void rotateRight(Node *&);
    void fixInsertRBTree(Node *&);
    int getColor(Node *&);
    void setColor(Node *&, int);
    void printTree(Node *&);


    Node* insertBST(Node *&, Node *&);

    int getBlackHeight(Node *);
public:
    RBTree();
    void insertValue(int);
    void printTree();

};