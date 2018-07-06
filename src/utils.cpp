#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "utils.hpp"

bool Utils::validInput(std::string input) {

    for(int i=0; i <input.length();i++){
        if(!isdigit(input[i]))
            return false;
    }
    return true;
}

int Utils::mapChar(char c) {
    return int(c);
}

void Utils::runAvlRight(Pile &p, NODE *&r) {
    p.push(r->key);
    if(r->right == NULL)
        return;
    runAvlRight(p,r->right);

}

void Utils::runRBTRight(Pile &p, Node *&r) {
    p.push(r->key);
    if(r->right == NULL)
        return;
    runRBTRight(p,r->right);
}

std::string Utils::intercalate(AvlTree avlTree, RBTree rbTree) {
    //constructTime = 0;
    Pile avlStack;
    Pile rbtStack;
    std::string pswd;

    clock_t start = clock();

    NODE *rAvl = avlTree.getRoot();
    Node *rRbt = rbTree.getRoot();

    runAvlRight(avlStack, rAvl);
    runRBTRight(rbtStack, rRbt);
    int hmax = std::max(avlStack.getSize(), rbtStack.getSize());

    for (int i = 0; i < hmax ; ++i) {
        if(rbtStack.getSize() > 0){
            pswd += (char) rbtStack.pop();
            //pswd += std::to_string(rbtStack.pop());
        }

        if(avlStack.getSize()>0){
            pswd += std::to_string(avlStack.pop());
            //pswd += (char) avlStack.pop();
        }


    }
    clock_t end = clock();
    constructTime = ((double) (end - start))/CLOCKS_PER_SEC;

    return pswd;
}
double Utils::getTime() {
    return constructTime;
}
