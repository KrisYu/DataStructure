#include <cstdlib>
#include <iostream>
#include <queue>

#include "BinaryTree.h"
using namespace std;

binaryTree::binaryTree(){
    root = NULL;
}

bool binaryTree::isEmpty(){
    return (root == NULL);
}

void binaryTree::BFS(){
    cout << "BFS "<<endl ;
    BFS(root);
    cout<<endl;
}

void binaryTree::BFS(node* root){
    queue<node*> q;
    q.push(root);
    
    while(!q.empty()){
        node* curr = q.front();
        cout << curr->data<<" ";
        q.pop();
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
}

void binaryTree::insert(int data){
    
    node* newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    node* curr;
    node* currTail;
    
    if(root == NULL){
        root = newNode;
    } else {
        curr = root;
        
        while(curr != NULL){
            currTail = curr;
            if(data > curr->data){
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }//end while
        
        if(data > currTail->data)
            currTail->right = newNode;
        else
            currTail->left = newNode;
    }
    cout << "Inserted " << data <<endl;
}

void binaryTree::postOrder(){
    cout<<"Post Order:"<<endl;
    postOrder(root);
    cout << endl;
}

void binaryTree::postOrder(node* root){
    if(root != NULL){
        postOrder(root->left);  
        postOrder(root->right);
	cout<<root->data<<" ";	
  }
}

void binaryTree::inOrder(){
    cout<<"In Order:"<<endl;
    inOrder(root);
    cout << endl;
}

void binaryTree::inOrder(node* root){
    if(root != NULL){
        inOrder(root->left);  
        cout<<root->data<<" ";	
        inOrder(root->right);
  }
}

void binaryTree::preOrder(){
    cout<<"Pre Order:"<<endl;
    preOrder(root);
    cout << endl;
}

void binaryTree::preOrder(node* root){
    if(root != NULL){
        cout<<root->data<<" ";        
        preOrder(root->left);  
        preOrder(root->right);
  }
}

int binaryTree::treeNodesCount(){
    cout << "tree nodes count :\n";
    return treeNodesCount(root);
    cout << endl;
}

int binaryTree::treeNodesCount(node* root){
    if(root == NULL)
        return 0;
    else 
        return 1 + treeNodesCount(root->left) + treeNodesCount(root->right);
}

int binaryTree::treeLeavesCount(){
    cout << "\ntree leaves count :\n";
    return treeLeavesCount(root);
    cout << endl;

}

int binaryTree::treeLeavesCount(node* root){
    if(root->right == NULL && root->left == NULL)
        return 1;
    else 
        return treeLeavesCount(root->left) + treeLeavesCount(root->right);
}

int binaryTree::treeHeight(){
    cout << "\ntree height :\n";
    return treeHeight(root);
    cout << endl;

}

int binaryTree::treeHeight(node* root){
    if(root ==NULL)
        return 0;
    else 
        return max(treeHeight(root->left),treeHeight(root->right)) + 1 ;
}

int binaryTree::max(int x, int y){
    return x>y ?x:y;
}

bool binaryTree::search(int data){
    cout << "\nSearch "<<data<<endl;
    return search(data,root);
}

bool binaryTree::search(int data, node* root){
    if(root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else
        return search(data, root->left) || search(data, root->right);
}

void binaryTree::insertRec(int data){
    
    if(root == NULL){
        node* newNode = new node;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    
        root = newNode;
        cout << "Inserted " << data <<endl;
    } else 
        insertRec(data,root);
}

void binaryTree::insertRec(int data, node* root){
    
    node* newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;         
    
    
    
    if(data > root->data){
        if(root->right == NULL)
            root->right = newNode;
        else
            insertRec(data,root->right);
    } else {
        if(root->left == NULL)
            root->left = newNode;
        else
            insertRec(data,root->left);
    }
    cout << "Inserted " << data <<endl;
}

void binaryTree::insertRec2(int data){
    root = insertRec2(data,root);
}

node* binaryTree::insertRec2(int data, node* root){
    
    node* newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;         
    
    if(root == NULL){
        root = newNode;
    } else {
        if(data > root->data){
            root->right = insertRec2(data,root->right);
        } else {
            root->left =  insertRec2(data, root->left);
        }
    }
    return root;
}

int binaryTree::findMax(){
    if(findMax(root) == NULL){
        cout <<"The tree is Empty\n";
        return -1;
    }
    else 
        return findMax(root)->data;  
}

node* binaryTree::findMax(node* root){
    if(root == NULL) return NULL;
    if(root->right == NULL) return root;
    else return findMax(root->right);
}

int binaryTree::findMin(){
    if(findMin(root) == NULL){
        cout <<"The tree is Empty\n";
        return -1;
    }
    else 
        return findMin(root)->data;
    
}

node* binaryTree::findMin(node* root){
    if(root == NULL) return NULL;
    if(root->left == NULL) return root;
    else return findMax(root->left);
}

void binaryTree::deleteKey(int data){
    deleteKey(data,root);
}

node* binaryTree::deleteKey(int data, node* root){
    if(search(data,root) == false)
        cout<<"No such node exists\n";
    if(data == root->data)// find the node to delete
    {
        if(root->left && root->right){//left && right nodes exits
            node* tmp = findMin(root->right);// the min of right tree
            root->data = tmp->data;
            root->right = deleteKey(root->data,root->right);//delete the min of the right
        } else {
            node* tmp =root;
            if(root->left == NULL)
                root = root->right;
            else if(root->right == NULL)
                root = root->left;
            free(tmp);
        }
    }
    else if (data < root->data)
        root->left = deleteKey(data, root->left);
    else
        root->right = deleteKey(data,root->right);
    return root;
}
