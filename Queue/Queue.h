/*
 * File:   Queue.h
 * Author: XueYu
 *
 * Created on September 4, 2015, 1:15 PM
 */

#ifndef QUEUE_H
#define	QUEUE_H

class Queue{
public:
    Queue();
    bool isEmpty();
    void enqueue(int data);
    int dequeue();
private:
    struct node{
        int data;
        node* next;
    };
    node* front;
    node* rear;
};



#endif	/* QUEUE_H */