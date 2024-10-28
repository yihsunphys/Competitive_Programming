#include <bits/stdc++.h>
using namespace std;
string s;
vector<string> ans;
char tmp[100005];
int sol = 0;
bool visited[10000];
void dfs(int idx){
  if(idx == s.size()) {
    ans.push_back(tmp);
    sol++;
    return;
  }
  char prev = '0';
  for(int i = 0; i < s.size(); i++){
    if(visited[i] == 0 && s[i]!=prev) {
      tmp[idx] = s[i];
      visited[i] = 1;
      prev = s[i];
      dfs(idx+1);
      visited[i] = 0;
    }
  }
}
int main() {
  cin >> s;
  sort(s.begin(), s.end());
  dfs(0);
  cout << sol << '\n';
  for(auto it:ans)
    cout << it << '\n';
}