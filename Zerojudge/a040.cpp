#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long 
#define endl '\n'
/*-------------------------------------------*/
int main(){
    int a,b;
    cin>>a>>b;
    bool k=0;
    for(int i=a;i<b;i++){
        string s=to_string(i);
        double sum=0;
        for(int j=0;j<s.size();j++){
            sum+=pow((int)(s[j]-'0'),s.size());
        }
        
        if(sum==i) {
            if(k==0){
            cout<<i;
            k=1;
            }
            else cout<<" "<<i;
        }
        
    } 
    if(k==0) cout<<"none";
}
