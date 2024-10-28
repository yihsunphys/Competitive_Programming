#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  while(cin >> s){
    list<char> lst;
    auto IT = lst.begin();
    for(auto it: s){
      if(it == '['){
        IT = lst.begin();
      }
      else if(it == ']'){
        IT = lst.end();
      }
      else{
        lst.insert(IT, it);
      }
    }
    for(auto it: s)
      cout << it;
    cout << '\n';
  }
}