#include <vector>
#include <iostream>
#include <queue>


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


int main() {
    
    priority_queue< pqNode, vector<pqNode>, compare> pq;
    
    pq.push(pqNode('B',2));
    pq.push(pqNode('C',3));
    pq.push(pqNode('A',1));
    pq.push(pqNode('D',4));
    
    while ( !pq.empty() )
    {
        cout << pq.top().value << endl;
        pq.pop();
    }
    
    
    return 0;
}

