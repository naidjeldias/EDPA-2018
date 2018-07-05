#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "pile.hpp"
#include "avl.hpp"
#include "rbt.hpp"

class Utils{

private:
    void runAvlRight(Pile &, NODE *&);
    void runRBTRight(Pile &, Node *&);
public:
    int mapChar(char);
    bool validInput(std::string);
    std::string intercalate(AvlTree avlTree, RBTree);

};