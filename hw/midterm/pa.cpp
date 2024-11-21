#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){

  int t;
  cin >> t;
  while(t--){
    ll n;
    cin >> n;
    if(n<10){
      ll ans = 1;
      for(int j = 2; j<=n; j++){
        ans^=j;
      }
      cout << ans << '\n';
    }
    else{
      if(n%4 == 0){
        cout << n << '\n';
      }
      else if((n-1)%4==0){
        cout << 1 << '\n';
      }
      else if((n+2)%4==0){
        cout << n+1 << '\n';
      }
      else {
        cout << 0 << '\n';
      }
    }
  }
  
}