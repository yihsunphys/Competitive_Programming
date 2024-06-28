#include <bits/stdc++.h>
using namespace std;
int main(){
  int t,sum;
  cin>>t;
  for(int i=0;i<t;i++){
    int a,b;
    sum=0;
    cin>>a>>b;
    for(int k=a;k<=b;k++){
        for(int j=1;j*j<=k;j++){
            if (j*j==k){
                sum+=k;
            }
        }
    }
    cout<<"Case "<<i+1<<": "<<sum<<endl;
  }
  return 0;
}
