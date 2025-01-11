#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    double sum;
    while(cin>>n){
        int a[n];
        sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if((sum/n)>59) cout<<"no\n";
        else cout<<"yes\n";
    }
}
