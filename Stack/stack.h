/*
 * File:   stack.h
 * Author: XueYu
 *
 * Created on September 4, 2015, 12:46 PM
 */

#ifndef STACK_H
#define	STACK_H

class Stack{
public:
    Stack();
    bool isEmpty();
    void push(int data);
    int pop();
private:
    struct node{
        int data;
        node* next;
    };
    node* top;
};


#endif	/* STACK_H */
