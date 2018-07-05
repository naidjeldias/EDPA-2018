#include <iostream>
#include "avl.hpp"
#include "rbt.hpp"
#include "utils.hpp"
#include <string>

enum letters {};

int main() {
    std::string key = "0" ;
    int count = 1;
    int opt = 0;

    RBTree rbTree;
    AvlTree avlTree;
    Utils utils;

    while(opt == 0){
        printf ("Gostaria de inserir os caracteres da chave ou gerar uma aleatoria:\n");
        printf ("1 - para inserir\n");
        printf ("2 - para gerar\n");
        scanf("%d",&opt);
        if(opt == 1){
            printf ("Insira os elementos da chave ou -1 para terminar a inserção\n");
            while (key != "-1"){
                printf ("\nInsira o elemento %d da chave ou -1 para terminar a inserção",count);
                std::cin >> key;
                if(key != "-1"){
                    if(key.length() > 1){
                        if(utils.validInput(key)) {
                            printf ("É digito\n");
                            avlTree.insertValue(atoi(key.c_str()));
                            //rbTree.insertValue(atoi(key.c_str()));
                        }else{
                            printf ("Entrada inválida\n");
                            count --;
                        }
                    } else {
                        if(isdigit(key[0])){
                            printf ("É digito\n");
                            avlTree.insertValue(atoi(key.c_str()));
                            //rbTree.insertValue(atoi(key.c_str()));
                        }else{
                            printf ("É caracter\n");
                            int value = utils.mapChar(key[0]);
                            rbTree.insertValue(value);
                            //avlTree.insertValue(value);
                        }
                    }
                }else{
                    printf ("Inserção terminada\n");
                }
                count++;
            }
        }else if (opt == 2){
            printf ("Opção 2\n");
        }else{
            opt = 0;
            printf ("Por favor inserir um dos valores acima\n");
        }
    }
    printf ("Imprimindo arvores...\n");
    printf ("AVL\n");
    avlTree.printTree();
    printf ("\nRubro negra\n");
    rbTree.printTree();

    return 0;
}