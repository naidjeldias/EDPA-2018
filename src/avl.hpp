
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Avl{

    public:
        typedef struct node{
            int key;
            struct node *left;
            struct node *right;
            int h;
        }NODE;

        typedef NODE* POINT;

        POINT rootAvl;

        void printTree(POINT r);

        POINT createNode(int key);

        int height (POINT r);
        POINT rightRotation(POINT r);
        POINT leftRotation(POINT r);
        POINT leftRightRotation(POINT r);
        POINT rightLeftRotation(POINT r);
        void initTree();
        POINT getRootAvl();
        POINT insert(POINT r, int key);

};