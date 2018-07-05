
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int key;
    struct NODE *left, *right;
    int h;
    explicit NODE(int);
};

class AvlTree{


private:
    NODE *root;

protected:
    NODE* insert(NODE *&, int key);
    void printTree(NODE *&);
    int height (NODE *&);
    NODE* rightRotation(NODE *&);
    NODE* leftRotation(NODE *&);
    NODE* leftRightRotation(NODE *&);
    NODE* rightLeftRotation(NODE *&);


public:
    AvlTree();
    void insertValue(int);
    void printTree();
    NODE* getRoot();


};