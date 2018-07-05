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

std::string Utils::intercalate(AvlTree avlTree, RBTree rbTree) {
    NODE* rootAvl = avlTree.getRoot();
    Node* rootRB  = rbTree.getRoot();

    return intercalTree(rootRB, rootAvl);
}

std::string Utils::intercalTree(Node *&r_avl, NODE *&r_rbt) {

    if(!r_avl && !r_rbt)
        return pswrd;
    else if(r_avl && !r_rbt){
        pswrd += std::to_string(r_avl->key);
        return intercalTree(r_avl->right,NULL);
    }else if(r_rbt && !r_avl){

    }



}