/* 
 * File:   MinHeap.h
 * Author: XueYu
 *
 * Created on October 8, 2015, 4:34 PM
 */

#include <vector>
using namespace std;

#ifndef MINHEAP_H
#define	MINHEAP_H

class MinHeap{
public:
    MinHeap();
    int size();
    void deleteMin();
    void insert(int data);
    int showMin();
    void display();
    void insertPercUp(int data);
    void deletePercDown();
    
private:
    //notice use a vector to implement heap, and the vector index starts form 0
    vector<int> v;
    int left(int idx);
    int right(int idx);
    int parent(int idx);
    void percDown(int idx);
    void percUp(int idx);
};

#endif	/* MINHEAP_H */

