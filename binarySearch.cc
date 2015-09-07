#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

int binarySearchWrapper(const vector<int> &a, int val, int left, int right){
    if (left <= right) {
        int mid = (left + right)/2;
        if (val  < a[mid]) return binarySearchWrapper(a, val, left, mid-1);
        else if (val > a[mid]) return binarySearchWrapper(a, val, mid + 1, right);
        else return mid;
    }
    return -1;
}


int binarySearch(const vector<int> &a, int val){
    return binarySearchWrapper(a, val, 0, a.size()-1);
}

int binarySearchLoop(const vector<int> &a, int val)
{
    int left = 0, right = a.size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if (val < a[mid]){
            right = mid - 1;
        } else if (val > a[mid]){
            left = mid + 1;
        } else
            return mid;
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
    
    sort(v1.begin(),v1.end());
    for (vector<int>::iterator itr = v1.begin(); itr != v1.end(); ++itr)
        cout << *itr <<" ";
    cout << endl;
    
    cout << "Type a number you want to find:";
    int val;
    cin >> val;
    
    if (binarySearch(v1,val) == -1) {
        cout << "The number you want to find not in the vector" << endl;
    } else {
        cout << "The number is at pos " << binarySearch(v1,val) << endl;
    }
    
    if (binarySearch(v1,val) == -1) {
        cout << "The number you want to find not in the vector" << endl;
    } else {
        cout << "The number is at pos " << binarySearchLoop(v1,val) << endl;
    }
    
    
    
    return 0;
    
}

