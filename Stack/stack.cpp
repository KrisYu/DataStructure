/*
 * File:   stack.cpp
 * Author: XueYu
 *
 * Created on September 4, 2015, 12:46 PM
 */

#include <cstdlib>
#include <iostream>

#include "Stack.h"

using namespace std;

Stack::Stack(){
    top = NULL;
}

bool Stack::isEmpty(){
    return top == NULL;
}

void Stack::push(int data){
    node* tmp = new node;
    tmp->data = data;
    tmp->next = NULL;
    if(top == NULL) top = tmp;
    else{
        tmp->next = top;
        top = tmp;
    }
}

int Stack::pop(){
    if(isEmpty()) {
        cout << "The stack is Empty"<<endl;
        return -1;
    }
    int val = top->data;
    node* tmp = top;
    top = top->next;
    delete tmp;
    return val;
}
