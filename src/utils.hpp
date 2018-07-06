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
    double constructTime;

public:
    int mapChar(char);
    bool validInput(std::string);
    std::string intercalate(AvlTree avlTree, RBTree);
    double getTime();

};