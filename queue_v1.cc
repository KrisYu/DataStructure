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


/*
 * File:   Queue.cpp
 * Author: XueYu
 *
 * Created on September 4, 2015, 1:15 PM
 */

#include <cstdlib>
#include <iostream>

#include "Queue.h"

using namespace std;

Queue::Queue(){
    front = rear = NULL;
}

bool Queue::isEmpty(){
    return front == NULL;
}

void Queue::enqueue(int data){
    
    node* tmp = new node;
    tmp->data = data;
    tmp->next = NULL;
    
    if(isEmpty()){
        front = rear = tmp;
    } else {
        rear->next = tmp;
        rear = rear->next;
    }
}

int Queue::dequeue(){
    if(isEmpty()){
        cout << "The queue is empty"<<endl;
        return -1;
    } else {
        node* tmp = front;
        int val = front->data;
        front = front->next;
        delete tmp;
        return val;
    }
}

/*
 * File:   main.cpp
 * Author: XueYu
 *
 * Created on September 4, 2015, 1:15 PM
 */

#include <cstdlib>
#include <iostream>
#include "Queue.h"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    
    Queue q;
    q.enqueue(0);
    q.enqueue(2);
    q.enqueue(3);
    
    
    cout << q.dequeue()<<endl;
    cout << q.dequeue()<<endl;
    cout << q.dequeue()<<endl;
    cout << q.dequeue()<<endl;
    
    
    return 0;
}


