#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

/*---------------------------*/
int main(){IOS;
  stack <char> a;
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++){
     if (s[i]=='(') a.push(s[i]);
     else if(s[i]==')'){
        if(a.empty()) {cout<<"Wrong";a.push(s[i]);break;}
        else if(a.top()=='(') a.pop();
        else {cout<<"Wrong";break;}
     }
     if(s[i]=='[')  a.push(s[i]);
     else if(s[i]==']'){ 
        if(a.empty()) {cout<<"Wrong";a.push(s[i]);break;}
        else if(a.top()=='[') a.pop();
        else {cout<<"Wrong";break;}
     }
  }
  if(a.empty()) cout<<"Right";
  return 0;
}
