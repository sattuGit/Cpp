#include<iostream>
#include "btree.h"

int main(){
    SimpleBTree<int> btree;
    btree.printTree();
    btree.addNode(1);
    btree.printTree();
    
    btree.addNode(12);
    /*
    btree.printTree();
    btree.addNode(16);
    btree.printTree();
    btree.addNode(122);
    btree.printTree();
    btree.addNode(0);
    btree.printTree();
    btree.addNode(12);
    btree.printTree();
    */
    return EXIT_SUCCESS;
}