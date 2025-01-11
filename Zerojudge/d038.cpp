#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
/*------------------------*/

ll fibo(int n){
   ll f[55]={};
   f[0]=0;
   f[1]=1;
   for(int i=2;i<=n;i++){
      f[i]=f[i-1]+f[i-2];
   }
   return f[n];
}


int main(){
   int n;
    while(cin>>n){
       if(n==0) break;
       cout<<fibo(n+1)<<endl;
    }
}
