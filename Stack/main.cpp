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
