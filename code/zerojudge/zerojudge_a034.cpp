#include <bits/stdc++.h>
using namespace std;
int main(){
  int x,i,k;
  while(cin>>x){
    for(i=32;i>=0;i--){
        if(x>=pow(2,i)){
            k=i;
            goto label_one;
        }
    }
    label_one:{
        for(i=k;i>=0;i--){
          if(x>=pow(2,i)){
              x-=pow(2,i);
              cout<<"1";
          }
          else{
            cout<<"0";
          }
        }
    }
    cout<<endl;
  }
  return 0;
}
