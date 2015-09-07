#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

int linearSearch(const vector<int> &a, int val){
    
    for (vector<int> :: size_type ix = 0; ix != a.size(); ix++) {
        if (a[ix] == val) {
            return ix;
        }
    }
    return -1;

}


int main(){
    
    cout << "Init int vector v1, store random number from 0 to 100..."<<endl;
    cout << "v1 :";
    
    srand((unsigned)time(0));
    vector<int> v1(10);
    for (vector<int>::iterator itr = v1.begin(); itr != v1.end(); ++itr) {
        *itr = rand() % 100;
    }
    
    for (vector<int>::iterator itr = v1.begin(); itr != v1.end(); ++itr)
        cout << *itr <<" ";
    cout << endl;
    
    cout << "Type a number you want to find:";
    int val;
    cin >> val;
    
    if (linearSearch(v1,val) == -1) {
        cout << "The number you want to find not in the vector" << endl;
    } else {
        cout << "The number is at pos " << linearSearch(v1,val) << endl;
    }
    
    
    
    return 0;
    
}
