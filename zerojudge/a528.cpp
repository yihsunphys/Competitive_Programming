#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define endl '\n'
/*--------------------------------*/
string a[1005];
bool cmp(string a, string b){
   if(a[0]=='-'&&b[0]!='-') return 1;
   if(b[0]=='-'&&a[0]!='-') return 0;
   if(b[0]=='-'&&a[0]=='-'){
      if(a.size()==b.size()){
        for(int i=0;i<a.size();i++){
         if(a[i]!=b[i]) return a[i]>b[i];
        }
        return 0;
      }
      else return a.size()>b.size();
   }
   else{
     if(a.size()==b.size()){
        for(int i=0;i<a.size();i++){
           if(a[i]!=b[i]) return a[i]<b[i];
        }
        return 0;
     }
     else return a.size()<b.size();
   }
}

int main(){IOS;
  int n;
  string s; 
  while(cin>>n){
    for(int i=0;i<n;i++){
       cin>>s;
       a[i]=s;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
       cout<<a[i]<<endl;
    }
  }
}
