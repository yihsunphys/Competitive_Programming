#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long

ll N, C;
ll sum = 0;
pii a[200005];
double cost = 0;
int main(){
  cin >> N >> C;  
  for(ll i = 0; i <N; i++) {
    cin >> a[i].first >> a[i].second;
    cost += (a[i].second - C)*(a[i].second - C);
    sum += a[i].first;
  }

  double mid = 1.0*sum/N; 
  for(ll i = 0; i < N; i++) {
    cost += (a[i].first - mid)*(a[i].first - mid);
  }
  cout << fixed << setprecision(15)<< cost << '\n';
}
