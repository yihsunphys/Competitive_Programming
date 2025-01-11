#include <bits/stdc++.h>
using namespace std;
int n;
int len;
int a[25];
bool used[25];
bool cmp(int x, int y) {
  return x>y;
}

bool dfs(int id, int finish, int now_len) {
  if(now_len == len){
    finish++;
    now_len = id = 0;
    if(finish == 3)
      return true;
  }
  for(int i = id; i < n; i++) {
    if(!used[i] && a[i]+now_len <= len){
      used[i] = 1;
      if(dfs(i+1, finish, a[i]+now_len))
        return true;
      used[i] = 0;
      if (now_len + a[i] == len)
        return false;
    }
  }
  return false;
}

int main(){
  int t, sum;
  cin >> t; 
  while(t--){
    cin >> n;
    sum = 0;
    for(int i = 0; i < n; i++){
      cin >> a[i]; 
      sum += a[i];
    }
    len = sum/4;
    memset(used, 0, sizeof(used));
    sort(a, a+n, cmp);
    if(a[0] > len || sum%4) cout << "no\n";
    else {
      if (dfs(0, 0, 0)) cout << "yes\n";
      else cout << "no\n";
    }
  }
}