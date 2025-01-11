#include <bits/stdc++.h>
using namespace std;
struct dic{
  int ascii;
  int cnt;
};
bool cmp(dic a, dic b) {
  if(a.cnt != b.cnt) return a.cnt<b.cnt;
  else return a.ascii>b.ascii;
}
dic a[1005];
int main(){
  string s;
  bool first = false;
  while(getline(cin,s)) {
    if(first) cout<<'\n';
    else first = true;
    for(int i = 0; i < 300; i++){
      a[i].ascii = i;
      a[i].cnt = 0;
    }
    for(int i = 0; i < s.size(); i++) {
      a[int(s[i])].cnt++;
    }
    sort(a, a+300, cmp);
    for(int i = 0; i < 300; i++){
      if(a[i].cnt != 0) cout<<a[i].ascii<<" "<<a[i].cnt<<"\n";
    }
    
  }
}
