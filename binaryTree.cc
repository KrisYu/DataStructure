#include <cstdlib>
#include <iostream>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

class binaryTree
{
public:
    binaryTree();
    bool isEmpty();
    void InOrder();
    void PreOrder();
    void PostOrder();
    
    
    int treeHeight();
    int treeNodeCount();
    int treeLeavesCount();
    void destroyTree();
}