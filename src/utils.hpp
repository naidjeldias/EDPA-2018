#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "avl.hpp"
#include "rbt.hpp"

class Utils{
private:
    std::string intercalTree(Node *&, NODE *&);

public:
    int mapChar(char);
    bool validInput(std::string);
    std::string intercalate(AvlTree avlTree, RBTree rbTree);
    std::string pswrd;

};