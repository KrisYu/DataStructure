
#include <iostream>
#include <cstdlib>

using namespace std;

const int V = 10;

//disjoint sets
int p[V];

void makeSet(){
    for (int i = 0; i < V; ++i)
        p[i] = i;
}

int find(int x){
    if (x == p[x])
        return x;
    else
        return find(p[x]);
}

void unionSet(int x, int y){
    int xParent = find(x);
    int yParent = find(y);
    p[xParent] = yParent;
}

int main(){

	makeSet();
	
	unionSet(2,9);
	unionSet(2,4);
	unionSet(2,3);

	unionSet(5,6);

	for (int i = 0; i < V; ++i)
	{
		cout << find(i) << " ";
	}


	return 0;
}