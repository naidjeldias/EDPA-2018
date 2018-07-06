#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

enum Color {RED, BLACK};


struct Node
{
    int key;
    int color;
    Node *left, *right, *parent;
    explicit Node(int);
};

class RBTree{

private:
    Node *root; /** ponteiro que guarda enderço da raiz */
    double constructTime;/**variável para armazenar o tempo de construção da árvore */
    int numElements;/**variável para armazenar número de elementos da árvore */

protected:
    void rotateLeft(Node *&ptr);
    void rotateRight(Node *&ptr);
    /**
     * @brief balancea a árvore
     * Executa um loop até o nó inserido e o pai dele tenham cores diferentes
     * Verifica se pai do nó é filho esquerdo ou direito do avó
     * verifica se o nó tio é vermelho, caso seja inverte as cores
     * Pai filho esquerdo e tio cor preto - se nó for inserido a direita, dupla rotação (esquerda-direita)
     * e inversão de cor entre pai e nó inserido, caso contrário somente uma rotação a direita e inversão de cor
     * Pai filho direito e tio cor preto - se nó for inserido a esquerda, dupla rotação (direita-esquerda)
     * e inversão de cor entre pai e nó inserido, caso contrário somente uma rotação a esquerda e inversão de cor
     * @param ptr endereço do nó inserido
     */
    void fixInsertRBTree(Node *&ptr);
    /**
     * @brief retorna a cor do nó
     * @param ptr endereço do nó
     * @return cor do nó
     */
    int getColor(Node *&ptr);
    /**
     * @brief seta a cor de um determinado nó
     * @param ptr endereço do nó
     * @param color a ser atribuida ao nó
     */
    void setColor(Node *&ptr, int color);
    /**
     * @brief Imprimir árvore
     * Imprime a ávore em percurso pré-ordem com os filhos de cada nó entre
     * parêntesis junto com a respectiva cor
     * @param r endereço da raiz da árvore a ser imprimida
     */
    void printTree(Node *&ptr);
    /**
     * @brief insere uma chave na árvore
     * Faz a busca onde o elemento deve ser inserido
     * define o endereço dos pais de cada nó
     * @param r endereço da raiz
     * @param ptr endereço do nó a ser inserido
     * @return endereço da raiz
     */
    Node* insertBST(Node *&r, Node *&ptr);

public:
    /**
     * @brief inicializa a árvore
     */
    RBTree();
    /**
     * @brief insere elmentos na árvore
     */
    void insertValue(int n);
    /**
   * @brief imprime na tela a árvore gerada
   */
    void printTree();
    /**
     * @return endereço da raiz
     */
    Node* getRoot();
    /**
     * @return  tempo total da construçao da árvore
     */
    double getTime();
    /**
     * @return número total de elementos inseridos
     */
    int getNumElements();

};