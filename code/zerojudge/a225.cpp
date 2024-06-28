#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long
#define endl '\n'
/*--------------------------------------*/
bool cmp(int a, int b){
   if(a%10==b%10) return a>b;
   else return a%10<b%10;
   
}
int a[1005];
int main(){IOS;
   int n;
   while(cin>>n){
      for(int i=0;i<n;i++){
         cin>>a[i];
      }
      sort(a,a+n,cmp);
      for(int i=0;i<n;i++){
         if(i==0) cout<<a[i];
         else cout<<" "<<a[i];
      }
      cout<<endl;
   }
}
