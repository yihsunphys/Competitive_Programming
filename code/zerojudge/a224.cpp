#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long
#define endl '\n'
/*--------------------------------------*/
int main(){IOS;
   int a[100]={};
   string s;
   while(cin>>s){
      int a[100]={};
      for(int i=0;i<s.size();i++){
         if(int(s[i])<65+26&&int(s[i])>=65) a[int(s[i])]++;
         else if(int(s[i])<97+26&&int(s[i])>=97) a[int(s[i])-32]++;
      }
      int k=0;
      for(int i=0;i<100;i++){
         if(a[i]%2!=0) k++;
      }
      if(s.size()%2==0){
         if(k!=0) cout<<"no...";
         else cout<<"yes !";
         cout<<endl;
      }
      else{
         if(k>1) cout<<"no...";
         else cout<<"yes !";
         cout<<endl;
      } 
   }
}
