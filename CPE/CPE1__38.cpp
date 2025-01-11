#include <bits/stdc++.h>
using namespace std;
int sum;

int deg(string s, int cnt){
    sum=0;
     for(int i=0;i<s.size();i++){
            sum+=int(s[i]-'0');
        }
      cnt++;
      if(sum<9) return 0;
      else if(sum==9) return cnt;
      else return deg(to_string(sum), cnt);
}

int main(){
    string s;
    while(cin>>s){
        if(s=="0") break;    
        int sum=0;
       if(deg(s,0)==0) cout<<s<<" is not a multiple of 9.\n";
        else cout<<s<<" is a multiple of 9 and has 9-degree "<<deg(s,0)<<"."<<endl;
    }
    return 0;
}
/*------------------------------------------*/
include <bits/stdc++.h>
using namespace std;
int main() {
  string s, str;
  while(cin>>s){
    if(s=="0") break;
    cout<<s;
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
      sum += s[i]-'0';
    }
    
    int cnt = 0;
    while(sum%9==0){
      cnt++;
      if(sum==9) break;
      str = to_string(sum); 
      sum = 0;
      for(int i = 0; i < str.size(); i++){
         sum += str[i]-'0';
      }
    }
    if(cnt!=0)
      cout<<" is a multiple of 9 and has 9-degree "<<cnt<<".\n";
    else
      cout<<" is not a multiple of 9.\n";
  }
}
