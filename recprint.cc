#include <iostream>

using namespace std;

void listN(int n){
  if(n == 0) return;
  cout<<n<<endl;
  listN(n-1);
}

void listN2(int n){
  if(n == 0) return ;
  listN(n-1);
  cout<<n<<endl;
}

int main(){
   listN(5);
   cout << endl;
   listN(5);
}
