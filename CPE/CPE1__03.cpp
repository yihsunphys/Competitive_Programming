#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int cnt = 0;
  while(getline(cin, s)){
    for(int i = 0; i < s.size(); i++){
      if(s[i]=='"'){
        if(cnt%2==0){
          cout<<"``";
          cnt++;
        }
        else{ 
          cout<<"''";
          cnt++;
        }
      }
      else cout<<s[i];
    }
    cout<<'\n';
  }
}
//一次" 一次``
