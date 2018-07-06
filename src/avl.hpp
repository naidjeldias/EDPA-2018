
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

struct NODE{
    int key;
    struct NODE *left, *right;
    int h;
    explicit NODE(int);
};

class AvlTree{

private:

    NODE *root;/** ponteiro que guarda enderço da raiz */
    double constructTime;/**variável para armazenar o tempo de construção da árvore */
    int numElements;/**variável para armazenar número de elementos da árvore */


protected:
    /**
     * @brief inserir elmento
     * Insere o elemnto na arvore e realiza o balanceamento
     * @param key o valor da chave a ser inserido
     * @param r endereço da raiz da árvore
     * @return endereço da raiz da árvore após balanceamento
     */
    NODE* insert(NODE *&r, int key);
    /**
     * @brief Imprimir árvore
     * Imprime a ávore em percurso pré-ordem com os filhos de cada nó entre parêntesis
     * @param r endereço da raiz da árvore a ser imprimida
     */
    void printTree(NODE *&r);
    /**
     * @brief Retorna altura
     * Retorna a altura da árvore que corresponde a altura do nó raiz
     * @param r enderço da raiz da árvore
     * @return alutra da árvore
     */
    int height (NODE *&r);
    /**
     * @brief Rotação a direita
     * Realiza uma rotação a direita do nó desbalanceado  \
     * O nó desbalanceado vira filho direto do seu filho esquerdo
     * @param r endereço do nó desbalanceado
     * @return endereço da nova raiz da subárvore após balanceamento
     */
    NODE* rightRotation(NODE *&r);
    /**
     * @brief Rotação a esquerda
     * Realiza uma rotação a esquerda do nó desbalanceado
     * O nó desvalanceado vira filho esquerdo do seu filho direito
     * @param r endereço do nó desbalanceado
     * @return endereço da nova raiz da subárvore após balanceamento
     */
    NODE* leftRotation(NODE *&r);
    /**
     * @brief Rotação dupla esquerda-direita
     * Realiza uma rotação a esquerda no filho esquerdo do nó desbalanceado
     * e uma rotação a direita do nó desbalanceado
     * @param r endereço do nó desbalanceado
     * @return  endereço da nova raiz da subárvore após balanceamento
     */
    NODE* leftRightRotation(NODE *&r);
    /**
     * @brief Rotação dupla direita-esquerda
     * Realiza uma rotação a direita no filho direito do nó desbalanceado
     * e uma rotação a esquerda do nó desbalanceado
     * @param r endereço do nó desbalanceado
     * @return  endereço da nova raiz da subárvore após balanceamento
     */
    NODE* rightLeftRotation(NODE *&r);


public:
    /**
     * @brief inicializa a árvore
     */
    AvlTree();
    /**
     * @brief insere elmentos na árvore
     */
    void insertValue(int);
    /**
     * @brief imprime na tela a árvore gerada
     */
    void printTree();
    /**
     * @return endereço da raiz
     */
    NODE* getRoot();
    /**
     * @return  tempo total da construçao da árvore
     */
    double getTime();
    /**
     * @return número total de elementos inseridos
     */
    int getNumElements();


};