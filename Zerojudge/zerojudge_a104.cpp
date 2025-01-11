#include <bits/stdc++.h>
using namespace std;
int main(){
 int t;
 while(cin>>t){
  int a[t];
  for(int i=0;i<t;i++){
    cin>>a[i];
  }
  sort(a,a+t);
  for(int j=0;j<t;j++){
  cout<<a[j]<<" ";
  }
  cout<<endl;
 }
 return 0;
}
