#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,x,count;
    while(cin>>a>>b){
        x=0;
        for(int i=a;i<=b;i++){
            if(i==1) continue;
            count=0;
            for(int j=2; j*j<=i;j++){
                if (i%j==0){
                    count++;
                    break;
                }
            }
            if(count==0) x++;
        }
       cout<<x<<endl;
    }
      return 0;
}
