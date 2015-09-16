/* 
 * File:   BinaryTree.h
 * Author: XueYu
 *
 * Created on September 14, 2015, 1:11 PM
 */

#ifndef BINARYTREE_H
#define	BINARYTREE_H

struct node{
    int data;
    node* left;
    node* right;
};

class binaryTree
{
public:
    binaryTree();
    
    void insert(int data);
    void insertRec(int data);
    void insertRec2(int data);
    void destroyTree();
    void deleteKey(int data);
    
    bool isEmpty();
    void inOrder();
    void preOrder();
    void postOrder();
    void BFS();
    bool search(int data);
    
    int findMax();
    int findMin();
    
    
    int treeHeight();
    int treeNodesCount();
    int treeLeavesCount();

 
private:
    node* root; 
    
    void inOrder(node* root);
    void preOrder(node* root);
    void postOrder(node* root);
    void BFS(node* root);
    void insertRec(int data, node* root);
    node* deleteKey(int data, node* root);
    
    int treeHeight(node* root);
    int treeNodesCount(node* root);
    int treeLeavesCount(node* root);
    int max(int x,int y);
    bool search(int data, node* root);
    node* insertRec2(int data, node* root);
    
    
    node* findMin(node *root);
    node* findMax(node *root);
    
};


#endif	/* BINARYTREE_H */

