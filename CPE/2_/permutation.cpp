#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  while(n--) {
    vector<char> v;
    cin >> s;
    sort(s.begin(), s.end());
    for(int i = 0; i < s.size(); i++)
      v.push_back(s[i]);
    do{
      for(auto it:v)
        cout<<it;
      cout<<'\n';
    }while(next_permutation(v.begin(), v.end()));
    cout<<'\n';
  }
}
//其實可以直接next_permutation string
