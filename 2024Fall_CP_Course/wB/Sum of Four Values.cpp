#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define  F first
#define S second
int main(){
  int n, target;
  cin >> n >> target;
  vector<pii> v(n+1);
  for(int i = 1; i <= n; i++){
    cin >> v[i].F;
    v[i].second = i;
  }
  sort(v.begin(), v.end());
  for(int i = 1; i <= n; i++){
    int tmp = target - v[i].F;
    for(int j = i+1; j <= n; j++){
      int l = j+1, r = n;
      while(l<r){
        if(v[j].F+v[l].F+v[r].F<tmp) l++;
        else if(v[j].F+v[l].F+v[r].F>tmp) r--;
        else {
          cout << v[i].S << " " <<  v[j].S << " "<< v[l].S << " "<< v[r].S ;
          return 0;
        }
      }
    }
  }
  cout << "IMPOSSIBLE";
} 