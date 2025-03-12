#include <bits/stdc++.h>
using namespace std;
bool dfs(int idx, int now, int cnt, int target_len, int target_cnt, vector<int> a, vector<bool> used){
  if(now == target_len){
    if(cnt+1 == target_cnt) return true;
    else return dfs(0, 0, cnt+1, target_len, target_cnt, a, used);
  }
  for(int i =idx; i<a.size(); i++){
    if(used[i]||now+a[i]>target_len || (i&&a[i] == a[i-1] &&!used[i-1])) continue;
    used[i] = 1;
    if(dfs(i+1, now+a[i], cnt, target_len, target_cnt, a, used)) return 1;
    used[i] = 0;
    if(now==0 || now+a[i] == target_len) return 0;
  }
  return 0;
}


int main(){
  int n;
  while(cin >> n){
    if(n == 0) break;
    int sum = 0, mx = 0;
    vector <int> a(n);
    vector <bool> used(n);
    for(auto &i:a){
      cin >> i;
      sum += i;
      mx = max(mx, i);
    }
    sort(a.rbegin(), a.rend());
    for(int i = mx; i <= sum; i++){
      if(sum%i) continue;
      if(dfs(0, 0, 0, i, sum/i, a, used)){
        cout << i << "\n";
        break;
      }
    }
  }
}