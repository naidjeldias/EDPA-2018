#include <iostream>
#include "utils.hpp"

int main() {
    srand(static_cast<unsigned int>(time(0)));
    std::string key = "0";
    int count = 1;
    int opt = 0;
    std::string randKey;

    RBTree rbTree;
    AvlTree avlTree;
    Utils utils;


    while(opt == 0){
        std::cout <<"Gostaria de inserir os caracteres da chave ou gerar uma aleatoria:\n";
        std::cout << "1 - para inserir\n";
        std::cout << "2 - para gerar\n";
        std::cin >> opt;
        if(opt == 1){
            while (key != "-1"){
                std::cout <<"\nInsira o elemento "<< count <<" da chave ou -1 para terminar a inserção";
                std::cin >> key;
                if(key != "-1"){
                    if(key.length() > 1){
                        if(utils.validInput(key)) {
                            avlTree.insertValue(atoi(key.c_str()));
                            //rbTree.insertValue(atoi(key.c_str()));
                        }else{
                            printf ("Entrada inválida\n");
                            count --;
                        }
                    } else {
                        if(isdigit(key[0])){
                            avlTree.insertValue(atoi(key.c_str()));
//                            rbTree.insertValue(atoi(key.c_str()));
                        }else{
                            int value = utils.mapChar(key[0]);
                            rbTree.insertValue(value);
                            //avlTree.insertValue(value);
                        }
                    }
                }else{
                    std::cout <<"Inserção terminada\n";
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
            std::cout <<"Por favor escolha uma das opções acima\n";
        }
    }

    if(!randKey.empty()){
        std::cout << "\nChave:\n";
        std::cout << randKey <<"\n";
    }
    std::cout <<"\nImprimindo arvores em pré ordem...\n";
    std::cout <<"AVL\n";
    avlTree.printTree();
    std::cout<<"\nRubro negra\n";
    rbTree.printTree();
    std::cout<<"\nSenha: "<<utils.intercalate(avlTree,rbTree)<<"\n";

    return 0;
}
