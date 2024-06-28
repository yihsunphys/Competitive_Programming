#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin>>n;
   while(n--){
    int a,b;
    cin>>a>>b;
    if(b>a||(a+b)%2!=0||(a-b)%2!=0){
        cout<<"impossible";
        continue;
    }
    cout<<(a+b)/2<<" "<<(a-b)/2<<endl;
   }
   return 0;
}
