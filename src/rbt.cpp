#include "rbt.hpp"

Node::Node(int data) {
    this->key = data;
    color = RED;
    left = right = parent = NULL;
}

RBTree::RBTree() {
    root = NULL;
}

int RBTree::getColor(Node *&node) {
    if (node == NULL)
        return BLACK;

    return node->color;
}

void RBTree::setColor(Node *&node, int color) {
    if (node == NULL)
        return;
    node->color = color;
}

Node* RBTree::insertBST(Node *&root, Node *&ptr) {
    if (root == NULL)
        return ptr;

    if (ptr->key < root->key) {
        root->left = insertBST(root->left, ptr);
        root->left->parent = root;
    } else if (ptr->key > root->key) {
        root->right = insertBST(root->right, ptr);
        root->right->parent = root;
    }

    return root;
}

void RBTree::insertValue(int n) {
    Node *node = new Node(n);
    root = insertBST(root, node);
    fixInsertRBTree(node);
}

void RBTree::rotateLeft(Node *&ptr) {
    Node *right_child = ptr->right;
    ptr->right = right_child->left;

    if (ptr->right != NULL)
        ptr->right->parent = ptr;

    right_child->parent = ptr->parent;

    if (ptr->parent == NULL)
        root = right_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = right_child;
    else
        ptr->parent->right = right_child;

    right_child->left = ptr;
    ptr->parent = right_child;
}

void RBTree::rotateRight(Node *&ptr) {
    Node *left_child = ptr->left;
    ptr->left = left_child->right;

    if (ptr->left != NULL)
        ptr->left->parent = ptr;

    left_child->parent = ptr->parent;

    if (ptr->parent == NULL)
        root = left_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = left_child;
    else
        ptr->parent->right = left_child;

    left_child->right = ptr;
    ptr->parent = left_child;
}

void RBTree::fixInsertRBTree(Node *&ptr) {
    Node *parent = NULL;
    Node *grandparent = NULL;
    while (ptr != root && getColor(ptr) == RED && getColor(ptr->parent) == RED) {
        parent = ptr->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left) {
            Node *uncle = grandparent->right;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            } else {
                if (ptr == parent->right) {
                    rotateLeft(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateRight(grandparent);
                std::swap(parent->color, grandparent->color);
                ptr = parent;
            }
        } else {
            Node *uncle = grandparent->left;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            } else {
                if (ptr == parent->left) {
                    rotateRight(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateLeft(grandparent);
                std::swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
    }
    setColor(root, BLACK);
}


void RBTree::printTree() {
    printTree(root);
}

void RBTree::printTree(Node *&ptr) {
    if(ptr != NULL){
        char c = (char) ptr->key;
        if(ptr->color == 0)
            std::cout << c <<"-red";
        else
            std::cout << c <<"-black";
        std::cout << "(";
        printTree (ptr->left);
        printTree (ptr->right);
        std::cout << ")";
    }
}

int RBTree::getBlackHeight(Node *node) {
    int blackheight = 0;
    while (node != NULL) {
        if (getColor(node) == BLACK)
            blackheight++;
        node = node->left;
    }
    return blackheight;
}

Node* RBTree::getRoot() {
    return root;
}
