#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define endl '\n'
/*---------------------------*/
int main(){IOS;
  int n;int a[100];
  while(cin>>n){
     for(int i=0;i<n;i++){
        cin>>a[i];
     }
     for(int j=0;j<ceil(n/2)+1;j++){
        bool k=0;
        for(int i=j;i<n-j;i++) {cout<<a[i]<<" ";k=1;}
        if(k) cout<<endl;
        k=0;
        for(int i=n-j-1;i>=j+1;i--) {cout<<a[i]<<" ";k=1;}
        if(k) cout<<endl;
     }
     cout<<endl;
  }
  return 0;
}
