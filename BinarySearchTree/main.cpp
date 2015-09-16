/* 
 * File:   main.cpp
 * Author: XueYu
 *
 * Created on September 14, 2015, 1:11 PM
 */

#include <cstdlib>
#include <iostream>

#include "BinaryTree.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    binaryTree tree1;
    tree1.insert(8);
    tree1.insert(2);
    tree1.insert(9);
    tree1.insert(1);
    tree1.insert(3);
    
    tree1.postOrder();
    tree1.inOrder();
    tree1.preOrder();
    
    tree1.BFS();
    
    cout << tree1.treeNodesCount();
    cout << tree1.treeLeavesCount();
    cout << tree1.treeHeight();
    
    
    cout << tree1.search(3);
    cout << tree1.search(11);
    
    
    
    binaryTree tree2;
    tree2.insertRec(8);    
    tree2.insertRec(2);
    tree2.insertRec(9);
    tree2.insertRec(1);
    tree2.insertRec(3);

    
    tree2.BFS();
    
    
    binaryTree tree3;
    tree3.insertRec2(8);    
    tree3.insertRec2(2);
    tree3.insertRec2(9);
    tree3.insertRec2(1);
    tree3.insertRec2(3);

    tree3.BFS();
    
    cout<<tree1.findMax()<<endl;
    cout << tree1.findMin()<<endl;
    
    tree1.deleteKey(3);
    tree1.BFS();
    

    return 0;
}

