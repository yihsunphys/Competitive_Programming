// G^k[1][n]，這個值即為從節點 1 到節點 n，恰好經過 k 條邊的路徑數量
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 1e9+7;
vector<vector<ll>> mul(vector<vector<ll>> A, vector<vector<ll>> B, int n){
  vector<vector<ll>> res(n+1, vector<ll>(n+1));
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      for(int k = 1; k <= n; k++)
        res[i][j] = (res[i][j] + A[i][k]*B[k][j])%MOD;
  return res;
}
vector<vector<ll>> pow(vector<vector<ll>> A, int k, int n){
  vector<vector<ll>> res(n+1, vector<ll>(n+1));
  for(int i = 1; i<= n; i++) res[i][i] = 1;
  if(k==0) return res;
  vector<vector<ll>> tmp = pow(A, k/2, n);
  if(k%2) return mul(mul(tmp,tmp,n),A,n);
  else return mul(tmp,tmp,n);
}
int main(){
  int n, m, k, u, v;
  cin >> n >> m >> k;
  vector<vector<ll>> G(n+1, vector<ll>(n+1));
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    G[u][v]++;
  }
  G = pow(G, k, n);
  cout << G[1][n] << '\n';
}