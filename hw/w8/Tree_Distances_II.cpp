// 要找一個node到其他所有點距離的sum
// 關鍵想法: 找出一個點u的解很容易 做dfs就好 
// 要找其他u鄰居點x的解 x的子樹深度-1 其餘+1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> tree(2000005);
vector<ll> sub_size(2000005); 
vector<ll> ans(2000005);
int n;
// 做dfs, 找各點子樹大小
void dfs1(int u, int p, int depth){
  ans[1] += depth;
  sub_size[u] = 1;
  for(auto x: tree[u]){
    if(x == p) continue;
    dfs1(x, u, depth+1);
    sub_size[u] += sub_size[x];
  }
}
// 算答案: n-2*sub_size[x]
void dfs2(int u, int p){
  for(auto x: tree[u]){
    if(x == p) continue;
    // ans[x] = ans[u] - sub_size[x] + (n - sub_size[x]);
    ans[x] = ans[u] + n - 2*sub_size[x];
    dfs2(x, u);
  }
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 1; i < n; i++){
    int u, v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  dfs1(1, -1, 0);
  dfs2(1, -1);
  for(int i = 1; i <= n; i++){
    cout << ans[i] << " ";
  }
}