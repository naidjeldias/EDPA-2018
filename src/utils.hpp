#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "pile.hpp"
#include "avl.hpp"
#include "rbt.hpp"

class Utils{

private:
    double constructTime;/**variável para armazenar o tempo da operação de intercala */

protected:
    /**
     * @brief Percorre a direita da AVL
     * Percorre o caminho mais a direita da árvore AVL construída
     * e empilha os elmentos na pilha passada como parâmetro
     * @param p endereço da raiz da árvore
     * @param r endereço da pilha
     */
    void runAvlRight(Pile &p, NODE *&r);
    /**
     * @brief Percorre a direita da rubro negra
     * Percorre o caminho mais a direita da árvore rubro negra construída
     * e empilha os elmentos na pilha passada como parâmetro
     * @param p endereço da raiz da árvore
     * @param r endereço da pilha
     */
    void runRBTRight(Pile &p, Node *&r);


public:
    /**
     * @brief retorna o valor da tabela ASCII
     * retorna o valor do caracter na tabela ASCII
     * @param c caracter
     * @return valor da tabela
     */
    int mapChar(char c);
    /**
     * @brief verifica se a entrada é válida
     * O programa não aceita entra de dois caracteres juntos
     * ou de um número junto com caracter
     * @param input entrada do usuário
     * @return se é válida ou não
     */
    bool validInput(std::string input);
    /**
     * @brief gera a senha a partir dos elementos das árvores
     * A partir dos valores empilhados a função constroí a senha intercalando
     * na ordem que os mesmo forem sendo retirados da pilha, primeiro da rubro negra depois da AVL
     * caso tiverem tamanhos diferentes segue a ordem dos elementos da pilha com mais elementos
     * @see runAvlRight()
     * @see runRBTRight()
     * @param avlTree a árvore AVL construída
     * @param rbTree a árvore rubro negra construída
     * @return a senha
     */
    std::string intercalate(AvlTree avlTree, RBTree rbTree);
    /**
     * @return tempo da operação de intercala
     */
    double getTime();

};