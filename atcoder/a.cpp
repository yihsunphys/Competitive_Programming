#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, c;
  cin >> n >> c;
  int pre = -1005;
  int num;
  int ans = 0;
  for(int i = 0; i < n; i++){
    cin >> num;
    if(num - pre >= c){
      ans++;
      pre = num;
    } 
  }
  cout << ans << '\n';
}