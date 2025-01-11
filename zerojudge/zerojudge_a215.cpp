#include <bits/stdc++.h>
using namespace std;
int main(){
 int n, m,i,sum;
 while (cin>>n>>m) {
    sum=0;
    i=0;
    while(1){
        sum=(n++)+sum;
        i++;
        if (sum>m){
          break;
        }
    }
    cout<<i<<endl;
 }
}
