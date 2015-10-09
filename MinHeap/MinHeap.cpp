#include "MinHeap.h"
#include <iostream>

using namespace std;

MinHeap::MinHeap(){
    
}

int MinHeap::size(){
    return v.size();
}

int MinHeap::left(int idx){
    int l = 2 * idx + 1;
    if(l < size())
        return l;
    return -1;
}

int MinHeap::right(int idx){
    int r = 2 * idx + 2;
    if(r < size())
        return r;
    return -1;
}

// notice -1/2 = 0
int MinHeap::parent(int idx){
    int prt = (idx - 1) /2 ;
    if(idx == 0)
        return -1;
    return prt;
}

void MinHeap::insert(int data){
    int idx = v.size();
    v.push_back(data);
    int prt = parent(idx);

    while(prt >= 0){
        if(v[prt] > v[idx])
            swap(v[prt],v[idx]);
        idx = prt;
        prt = parent(idx);
        if(prt < 0) break; 
    }
    
}

int MinHeap::showMin(){
    if(size() >= 0)
        return v[0];
    cout << "The heap is empty"<<endl;
    return -1;
}

void MinHeap::deleteMin(){
    if(size() > 0){
        
        swap(v[size()-1],v[0]);
        v.pop_back();
        
        int idx = 0;
        int l = left(idx);
        int r = right(idx);
        int smallIdx;
        
        while(l > 0 ){
            smallIdx = ( v[idx] > v[l] ) ? l : idx;
            if(r != -1 && v[r] < v[smallIdx] )
                smallIdx = r;
            
            if(smallIdx == idx)
                break;
            else{
                swap(v[idx],v[smallIdx]);
                
                idx = smallIdx;
                l = left(idx);
                r = right(idx);
            }
            if(l < 0) break;
        }
    }else {
        cout << "The heap is empty" << endl;
    }
}

void MinHeap::display(){
    for ( vector<int>::iterator i = v.begin(); i != v.end(); i++ ) {
        cout << *i << " ";
    }
    cout << endl;
}

void MinHeap::percUp(int idx){
    int prt = parent(idx);
    if(idx >= 0 && prt >=0 && v[prt] > v[idx] ){
        swap(v[prt],v[idx]);
        percUp(prt);
    }
}

void MinHeap::insertPercUp(int data){
    int idx = v.size();
    v.push_back(data);
    
    percUp(idx);
}

void MinHeap::deletePercDown(){
    if(size() > 0){
        
        swap(v[size()-1],v[0]);
        v.pop_back();
        
        percDown(0);
    }
}

void MinHeap ::percDown(int idx){
    int l = left(idx);
    int r = right(idx);
    //init smallIdx for the return case
    int smallIdx = idx;
    
    if( l != -1 && v[idx] > v[l] )
        smallIdx = l;
    if( r != -1 && v[smallIdx] > v[r])
        smallIdx = r;
    
    if(smallIdx == idx)
        return;
    else{
        swap(v[idx],v[smallIdx]);
        percDown(smallIdx);
    }
}