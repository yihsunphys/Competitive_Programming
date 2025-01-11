#include <bits/stdc++.h>
using namespace std;
int a[200005];
int t, n;
int sum = 0;
vector<vector<int>> ans;
vector<int> tmp;
void dfs(int id){
  if(id == n) return;
  if(sum == t) ans.push_back(tmp);
  for(int i = id+1; i < n; i++) {
    if(a[i] == a[i-1] && i > id+1) continue; //重點 
    sum+=a[i];
    tmp.push_back(a[i]);
    dfs(i); //重點
    sum-=a[i];
    tmp.pop_back();
  }
}
int main() {
  while(cin >> t){
    if(t == 0) break;
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> a[i];
    ans.clear(); //記得初始化
    sum = 0;
    dfs(-1);
    cout << "Sums of " << t <<":\n";
    if(ans.empty()) cout << "NONE\n";
    else 
      for(auto it: ans){
        for(auto it2 = it.begin(); it2 != it.end(); it2++) {
          cout << *it2 << "+\n"[it2 == it.end()-1];
        }
      }
  } 
}