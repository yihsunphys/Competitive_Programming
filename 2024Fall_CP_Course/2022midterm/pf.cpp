#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> pre(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }pre[0] = 0;
  for(int id = 0; id <= n; id++){
    i = id%=n;
    for(int j = i-1; j >= 0; j--){
      if(a[j] >= a[i]){
        pre[i] = j;
        cout<< j+1 << " ";
        break;
      } 
      else{
        if(j<i){
        j = pre[j] + 1;
        if(j == 1) j = n;
        }
      }
    }
  }
}