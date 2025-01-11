#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n;
int subtree_size[MAXN]; //子節點數量
vector<int> tree[MAXN];
void dfs(int root) { //樹的節點數量(不包含root)
    for(auto it: tree[root]) {
        dfs(it);
        subtree_size[root] += subtree_size[it]+1;
    }
}
int main() {
  cin >> n;
  for(int i = 2; i <= n; i++) {
    int boss;
    cin >> boss;
    tree[boss].push_back(i);
  }
  dfs(1);
  for(int i = 1; i <= n; i++)
    cout << subtree_size[i] << " ";
}
