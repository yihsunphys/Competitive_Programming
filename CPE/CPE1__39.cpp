#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(cin>>s){
         if(s=="0")  break;
        int a=0,b=0;
        for(int i=0; i<s.size(); i+=2){
            a+=int(s[i]-'0');
        }
        for(int i=1; i<s.size(); i+=2){
            b+=int(s[i]-'0');
        }

        if(a>b) swap(a,b);
        if((b-a)%11==0) cout<<s<<" is a multiple of 11."<<endl;
        else cout<<s<<" is not a multiple of 11."<<endl;
    }
    return 0;
}
/*---------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  while(cin>>s){
  if(s=="0") break;
  int sum1 = 0, sum2 = 0;
    for(int i = s.size()-1; i>=0; i-=2){
      if(i>=0) sum1 += s[i]-'0';
      if(i-1>=0) sum2 += s[i-1]-'0';
    }
    cout<<s;
    if(abs(sum1-sum2)%11 ==0) 
      printf(" is a multiple of 11.\n");
    else
      printf(" is not a multiple of 11.\n");
  }
}
