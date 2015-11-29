#include <vector>
#include <iostream>
#include <queue>
#include <stdexcept>

using namespace std;


class pqNode{
public:
    pqNode(char v, int p):value(v),priority(p){ }          
    int priority;
    char value;
};

struct  compare
{
    bool operator()(const pqNode &l, const pqNode &r){
        return l.priority > r.priority;
    }
};

class MinHeap{
private:
    priority_queue< pqNode, vector<pqNode>, compare> pq;
public:
    void add(pqNode t){
        pq.push(t);
    }
    pqNode min(){
        if(!pq.empty()){
            pqNode t = pq.top();
            pq.pop();
            return t;
        }
        throw invalid_argument( "PQ is empty" );
    }
    
    
};


int main() {
    
    MinHeap h1;
        
    h1.add(pqNode('B',2));
    h1.add(pqNode('C',3));
    h1.add(pqNode('A',1));
    h1.add(pqNode('D',4));
    
    cout << h1.min().value<<endl;
    cout << h1.min().value<<endl;
    cout << h1.min().value<<endl;
    cout << h1.min().value<<endl;
    
    cout << h1.min().value<<endl;
   

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

