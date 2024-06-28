#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y){
  if(x>y) swap(x, y);
  if(y%x == 0) return x;
  else return gcd(y%x, x);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while(cin >> n){
      if(n == 0) break;
	  int g = 0;
	  for(int i = 1; i < n; i++){
	    for(int j = i+1; j <= n; j++){
	      g += gcd(i, j);
	    }
	  }
	  cout << g << '\n';
  }
}
