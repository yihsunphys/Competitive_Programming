#include <bits/stdc++.h>
using namespace std;
vector<string> Generate_graycode(int n){
  if(n == 1) return {"0", "1"};
  vector<string> Previous_graycode = Generate_graycode(n-1);
  vector<string> Reverse_graycode = Generate_graycode(n-1);
  reverse(Reverse_graycode.begin(), Reverse_graycode.end());
  vector<string> ans;
  for(int i = 0; i < Previous_graycode.size(); i++) {
    Previous_graycode[i]+='0';
    ans.push_back(Previous_graycode[i]);
  }
  for(int i = 0; i < Previous_graycode.size(); i++) {
    Reverse_graycode[i]+='1';
    ans.push_back(Reverse_graycode[i]);
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  vector<string> ans =  Generate_graycode(n);
  for(auto it: ans)
    cout << it << '\n';
}