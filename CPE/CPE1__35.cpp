#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int id = 0;
  while(n--){
    id++;
    int a, b;
    cin >> a>> b;
    int ans = 0;
    if(a%2==0) a++;
    if(b%2==0) b--;
    if(a<=b){
      int n = (b-a)/2;
      if(n%2==0)
        ans = ((b+a)/2)*(n+1);
      else
        ans = (b+a)*(n/2+1);
    }
    cout<<"Case "<<id<<": "<<ans<<'\n';
  }
}
