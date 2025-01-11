#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    while(cin>>a>>b){
        if(a==0&&b==0) break;
        int sum=0;
        for(int i=a;i<=b;i++){
            if(int(sqrt(i))*int(sqrt(i))==i)  sum++;
        }
        cout<<sum<<endl;
    }

}
