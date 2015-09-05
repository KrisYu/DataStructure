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

/*
 * File:   main.cpp
 * Author: XueYu
 *
 * Created on September 4, 2015, 12:46 PM
 */

#include <cstdlib>
#include <iostream>
#include "Stack.h"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    
    cout << s.pop()<<endl;
    cout << s.pop()<<endl;
    cout << s.pop()<<endl;
    cout << s.pop()<<endl;
    
    
    return 0;
}


