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
