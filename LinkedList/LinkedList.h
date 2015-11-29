/* 
 * File:   LinkedList.h
 * Author: XueYu
 *
 * Created on November 28, 2015, 1:27 PM
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

class LinkedList{
    
private:
    typedef struct node{
     int data;
     node* next;
    }* nodePtr;
   
    nodePtr head;
    
    void traverseRec(nodePtr head);
    bool findVal(nodePtr head, int val);
    nodePtr find(nodePtr head, int val);
    int count(nodePtr head);
    void deleteNodeRec(nodePtr head, int n);
    void reverseListRec(nodePtr & head);

public:
    LinkedList();
    void insertFront(int n);
    void traverse1();
    void traverse2();
    void traverseRec();
    bool findVal(int val);
    nodePtr find(int val);
    int count();
    void deleteNode(int n);
    void deleteNodeRec(int n);
    void reverseList();
    void reverseListRec();
};


#endif	/* LINKEDLIST_H */

