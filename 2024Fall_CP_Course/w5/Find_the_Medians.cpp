#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  //分為 mid, L, R
  int mid = -1;
  priority_queue<int> L;
  priority_queue<int, vector<int>, greater<int>> R;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    if(mid == -1) mid = num;
    else{
    if(num<mid){
      if(L.size()<R.size()){
        L.push(num); 
      }
      else {
        L.push(num);
        R.push(mid);
        mid = L.top(); L.pop();
      }
    }
    else{
      if(L.size()<R.size()){
        R.push(num);
        L.push(mid);
        mid = R.top(); R.pop();
      }
      else {
        R.push(num);  
      }
    }
    }
    cout << mid << " \n"[i==n-1];
  }
}