#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long
#define endl '\n'
/*-------------------------------------------*/
int main(){
    int a[8],b[8],suma=0,sumb=0;
    for(int i=0;i<4;i++) {
        cin>>a[i];
        suma+=a[i];
    }
    for(int i=0;i<4;i++) {
        cin>>b[i];
        sumb+=b[i];
    }
    cout<<suma<<":"<<sumb<<endl;
    int sum1=0,sum2=0;
    for(int i=4;i<8;i++) {
        cin>>a[i];
        sum1+=a[i];
    }
    for(int i=4;i<8;i++) {
        cin>>b[i];
        sum2+=b[i];
    }
    cout<<sum1<<":"<<sum2<<endl;
    if(suma>sumb&&sum1>sum2) cout<<"Win";
    else if(suma<sumb&&sum1<sum2) cout<<"Lose";
    else cout<<"Tie";
    return 0;
}
