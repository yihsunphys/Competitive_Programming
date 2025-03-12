#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> Gray_code(int n){
  if(n == 1) return {"0", "1"};
  vector<string> prev = Gray_code(n-1);
  vector<string> rev =  Gray_code(n-1);
  reverse(rev.begin(), rev.end());
  vector<string> ans;
  for(auto it: prev){
    ans.push_back('0'+it);
  }
  for(auto it: rev){
    ans.push_back('1'+it);
  }
  return ans;
}
int main() {
  cin >> n;
  vector<string> ans = Gray_code(n);
  for(auto it: ans)
    cout << it << '\n';
}