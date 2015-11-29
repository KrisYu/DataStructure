/* 
 * File:   main.cpp
 * Author: XueYu
 *
 * Created on November 28, 2015, 1:27 PM
 */

#include <cstdlib>
#include<iostream>
#include "LinkedList.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    LinkedList l1;
    l1.insertFront(10);
    l1.insertFront(20);
    l1.insertFront(30);
    l1.insertFront(35);
    l1.insertFront(40);
    l1.insertFront(5);
    
    cout << "Traverse List via while loop:"<<endl;
    l1.traverse1(); 
    
    cout << "Traverse List via for loop:"<<endl;
    l1.traverse2();
    
//    cout << l1.head << endl;
    cout << "Traverse List via recursive ways:"<<endl;
    l1.traverseRec();
    
//    cout << l1.head << endl;
    
    cout << endl << endl << "find things, find 5:" << endl;
    cout << "pointer loc: " << l1.find(5) << endl;
    cout << "in list? " << l1.findVal(5) << endl;
    
    cout << endl << "find things, find 55:" << endl;
    cout << "pointer loc: " << l1.find(55) << endl;
    cout << "in list? " << l1.findVal(55) << endl; 
    
    cout << endl <<"count of nodes: " << l1.count() << endl;

    cout << "delete use while loop:";
    cout << "delete 5:";
    l1.deleteNode(5);
    cout << "Traverse List via recursive ways:"<<endl;
    l1.traverseRec();
    
    cout <<endl<< "delete use while loop:";
    cout << "delete 35:";
    l1.deleteNode(35);
    cout << "Traverse List via recursive ways:"<<endl;
    l1.traverseRec();
    
    
    cout << endl << "delete use recursive way:";
    cout << "delete 40:";
    l1.deleteNode(40);
    cout << "Traverse List via recursive ways:"<<endl;
    l1.traverseRec();
    
    cout <<endl<< "delete use recursive way:";
    cout << "delete 10:";
    l1.deleteNode(10);
    cout << "Traverse List via recursive ways:"<<endl;
    l1.traverseRec();   
    
    
    cout << endl <<  "Now insert from front again, insert 45,55,60" << endl;
    l1.insertFront(45);
    l1.insertFront(55);
    l1.insertFront(60);
    cout << "Traverse List via recursive ways:"<<endl;
    l1.traverseRec();   
    
    cout<< endl << "Reverse List via while loop :  "<<endl;
    l1.reverseList();
    cout << "Traverse List via recursive ways:"<<endl;
    l1.traverseRec();   
    
    cout << endl << "Reverse List via recursive way :  "<<endl;
    l1.reverseListRec();
    cout << "Traverse List via recursive ways:"<<endl;
    l1.traverseRec();   
    
    
    return 0;
}

