#include <iostream>
#include "utils.hpp"



enum letters {};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    std::string key = "0";
    int count = 1;
    int opt = 0;
    std::string randKey;

    RBTree rbTree;
    AvlTree avlTree;
    Utils utils;
    Pile pile1;

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
//                            rbTree.insertValue(atoi(key.c_str()));
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
            //tamanho da chave a ser gerada
            int size = 20 + std::rand() % (100-20+1);
            for(int j=0; j < size; j++){
                int value;
                //caso seja 1 gerar números caso contrário letras
                int type = std::rand() % 2;
                if(type == 1){
                    // gerar números até 999
                    value = std::rand() % 1000;
                    avlTree.insertValue(value);
                    //rbTree.insertValue(value);
                    randKey = randKey+" "+std::to_string(value);

                }else{
                    //intervalo de valores da tabela ASCII a ser gerado
                    value = 58 + rand() % (126 - 58 +1);
                    rbTree.insertValue(value);
                    //avlTree.insertValue(value);
                    char aChar = (char) value;
                    randKey = randKey+" "+aChar;
                }
            }
            break;
        }else{
            opt = 0;
            printf ("Por favor inserir um dos valores acima\n");
        }
    }

    std::cout << "Chave gerada:\n";
    std::cout << randKey <<"\n";
    printf ("Imprimindo arvores...\n");
    printf ("AVL\n");
    avlTree.printTree();
    printf ("\nRubro negra\n");
    rbTree.printTree();
    std::cout<<"\nSenha: "<<utils.intercalate(avlTree,rbTree);

    return 0;
}