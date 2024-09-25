#include <bits/stdc++.h>
using namespace std;
int a[205];
bool visited[205];
int ans[205];
int n, m;
void print(){
  for(int i = 0; i < m; i++)
    cout << ans[i] << " \n"[i==m-1];
}
void dfs(int idx, int prev){
  if(idx == m) 
    print();
  for(int i = prev+1; i < n; i++){
    if(visited[i] == 0){
      ans[idx] = a[i];
      visited[i] = 1;
      dfs(idx+1, i);
      visited[i] = 0;
    }
  }
}
int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);
  dfs(0, -1);
}