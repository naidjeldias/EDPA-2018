#include <iostream>
#include "avl.hpp"
#include "rbt.hpp"

int main() {
    int key = 0 ;
    int count = 1;

    RBTree rbTree;
    AvlTree avlTree;

    printf ("Insira os elementos da arvore e -1 para terminar a inserção\n");
    while (key != -1){
        printf ("\nInsira o elemento %d da arvore ou -1 para terminar a inserção",count);
        scanf("%d",&key);
        if(key != -1){
            avlTree.inserValue(key);
            rbTree.insertValue(key);
        }else{
            printf ("Inserção terminada\n");
        }
        count++;
    }
    printf ("Imprimindo arvores...\n");
    printf ("AVL\n");
    avlTree.printTree();
    printf ("\nRubro negra\n");
    rbTree.printTree();

    return 0;
}