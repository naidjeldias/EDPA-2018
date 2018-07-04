#include <iostream>
#include "avl.hpp"



int main() {
    int key = 0 ;
    int count = 1;

    Avl avl;
    avl.initTree();
    Avl::POINT avl_root = avl.getRootAvl();


    printf ("Insira os elementos da arvore e -1 para terminar a inserção\n");
    while (key != -1){
        printf ("\nInsira o elemento %d da arvore ou -1 para terminar a inserção",count);
        scanf("%d",&key);
        if(key != -1){
            avl_root = avl.insert(avl_root,key);
            avl.printTree(avl_root);
        }else{
            printf ("Inserção terminada\n");
        }
        count++;
    }
    printf ("Imprimindo arvore...\n");
    avl.printTree(avl_root);

    return 0;
}