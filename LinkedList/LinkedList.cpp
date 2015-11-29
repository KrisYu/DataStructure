#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList(){
    head = NULL;
}

void LinkedList::insertFront(int n){
    nodePtr tmp = new node;
    tmp->data =n;
    tmp->next = NULL;
    
    if(head == NULL)
        head = tmp;
    else{
        tmp->next = head;
        head = tmp;
    }
}

void LinkedList::traverse1(){
    nodePtr tmp = head;
    while(tmp){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void LinkedList::traverse2(){
    for(nodePtr curr = head; curr != NULL; curr = curr->next)
        cout << curr->data << " ";
    cout << endl;
}

void LinkedList::traverseRec(nodePtr head){
    if(head == NULL) return;
    cout << head->data << " ";
    traverseRec(head->next);
}

void LinkedList::traverseRec(){
    traverseRec(head);
}

bool LinkedList::findVal(nodePtr head, int val){
    if(head == NULL) return false;
    if(head->data == val ) return true;
    return findVal(head->next,val);
}

bool LinkedList::findVal(int val){
    return findVal(head,val);
}

LinkedList::nodePtr LinkedList::find(nodePtr head, int val){
    if(head == NULL) return NULL;
    if(head->data == val) return head;
    return find(head->next,val);
}

LinkedList::nodePtr LinkedList::find(int val){
    return find(head,val);
}

int LinkedList::count(nodePtr head){
    if(head == NULL) return 0;
    return 1 + count(head->next);
}

int LinkedList::count(){
    return count(head);
}

void LinkedList::deleteNode(int n){
    //if not found, just return
    if(!findVal(n)) return;
    
    nodePtr prev = NULL;
    nodePtr curr = head;
    //the node is at head
    if(head->data == n){
        head = head->next;
        delete curr;
    } else {
        while(curr->data != n){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
    }
}

void LinkedList::deleteNodeRec(nodePtr head, int n){
    if(!findVal(n)) return;
    
    node* prev = NULL;
    node* curr = head;
    //the node is at head
    if(head->data == n){
        head = head->next;
        delete curr;
    } else {
        deleteNodeRec(curr->next,n);
    }
}

void LinkedList::deleteNodeRec(int n){
    deleteNodeRec(n);
}

void LinkedList::reverseList(){
    nodePtr prev = NULL;
    nodePtr curr = head;
    nodePtr next = NULL;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void LinkedList::reverseListRec(nodePtr & head){
    nodePtr first;
    nodePtr rest;
    
    //if it is an empty list
    if( head == NULL) return ;
    
    first = head;
    rest = first->next;
    
    // if it is a list with just one node
    if (rest == NULL) return ;
    
    reverseListRec(rest);
    
    first->next->next = first;
    
    first->next = NULL;
    head = rest;
}

void LinkedList::reverseListRec(){
    reverseListRec(head);
}