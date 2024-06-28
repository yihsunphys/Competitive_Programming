#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[] ={"!@#%^&*()_+", "1234567890-=", "qwertyuiop[]\\", "asdfghjkl;'","zxcvbnm,./"};
  map<char, char>mp;
  for(int i = 0; i < 5; i++){
    for(int j = 2; j < s[i].size(); j++){
      mp[s[i][j]] = s[i][j-2]; 
    }
  }
  string str;
  while(getline(cin, str)) {
    for(int i = 0; i < str.size(); i++) {
      if(isupper(str[i])) str[i] = str[i] - 'A' +'a';
      if(mp.count(str[i])) cout<<mp[str[i]];
      else cout<<str[i];
    }
    cout<<'\n';
  }
}
//要大寫換小寫
