#include <bits/stdc++.h>
using namespace std;
void allRingDown(int);
void allRingUp(int);
//遞迴步驟: 為了取下第n環 先取下1~n-2個環 -> 取下第n環 -> 1至n-2個環全上 -> 變成n-1個環的子問題
void allRingDown(int n){
  if(n>0){
    allRingDown(n-2);
    cout << "Move ring " << n <<  " out\n";
    allRingUp(n-2);
    allRingDown(n-1);
  }
}
void allRingUp(int n){
  if(n>0){
    allRingUp(n-1);
    allRingDown(n-2);
    cout << "Move ring " << n <<  " in\n";
    allRingUp(n-2);
  }
}

int main() {
  int n;
  cin >> n;
  allRingDown(n);
}
