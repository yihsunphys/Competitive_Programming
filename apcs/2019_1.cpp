#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long
#define endl '\n'
/*-------------------------------------------*/
int a1,a2,b1,b2,c1,c2,n;
int y1(int x1){
    return a1*x1*x1+b1*x1+c1;
}
int y2(int x2){
    return a2*x2*x2+b2*x2+c2;
}

int main(){  
    cin>>a1>>b1>>c1>>a2>>b2>>c2>>n;
    int max=y1(0)+y2(n);
    for(int i=0;i<=n;i++){
        if((y1(i)+y2(n-i))>max){
            max=y1(i)+y2(n-i);
        }
    }
    cout<<max;
}
