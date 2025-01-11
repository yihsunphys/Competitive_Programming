#include <bits/stdc++.h>
using namespace std;
void ini(string &a, string &b) {
  if(a.size() > b.size()) swap(a, b);
  while(a.size() < b.size()) {
    a = '0' + a;
  }
}

string add(string s1, string s2) {
  string ans = "";
  int carry = 0;
  ini(s1, s2);
  for( int i = s1.size()-1; i >= 0; i--) {
    int sum = (s1[i]-'0') + (s2[i]-'0') + carry;
    ans += sum%10 + '0';
    carry = sum/10;
  }
  if(carry) ans += '1';
  reverse(ans.begin(), ans.end());
  return ans;
}

string mul(string s1, string s2) {
  string ans = "0";
  for(int i = s1.size()-1; i>= 0; i--) {
    int a = s1[i] - '0';
    if(i != s1.size()-1) s2+='0';
    for(int i = 0; i < a; i++){
      ans = add(s2, ans);
    }
  }
  while(ans[0] == '0' && ans.size()!=1) ans.erase(0, 1);
  return ans;
}

int main () {
  string s1, s2;
  while(cin >> s1 >> s2) {
    cout << mul(s1, s2) <<'\n';
  }
}
