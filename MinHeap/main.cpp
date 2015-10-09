/* 
 * File:   main.cpp
 * Author: XueYu
 *
 * Created on October 8, 2015, 4:34 PM
 */

#include <cstdlib>
#include <iostream>

#include "MinHeap.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    cout << "h1 " << endl;
    
    MinHeap h1;
    h1.insert(16);
    h1.insert(21);
    h1.insert(24);
    h1.insert(31);
    h1.insert(65);
    h1.insert(26);
    h1.insert(32);
    h1.insert(14);
    h1.insert(19);
    h1.insert(68);
    h1.insert(13);
    
    h1.display();

    cout << "h1 delete min via delete function" << endl;
    
    while(h1.size()>0)
    {
        h1.deleteMin();
        h1.display();   
    }
        

    cout << endl;
    
    
    cout << "h2 by recursion" << endl; 
           
    MinHeap h2;
    
    h2.insertPercUp(16);
    h2.insertPercUp(21);
    h2.insertPercUp(24);
    h2.insertPercUp(31);
    h2.insertPercUp(65);
    h2.insertPercUp(26);
    h2.insertPercUp(32);
    h2.insertPercUp(14);
    h2.insertPercUp(19);
    h2.insertPercUp(68);
    h2.insertPercUp(13);
    
    h2.display();
    
    cout << "h2 delete via recursion" << endl;
    while(h2.size()){
        h2.deletePercDown();
        h2.display();
    }
    
    return 0;
}

