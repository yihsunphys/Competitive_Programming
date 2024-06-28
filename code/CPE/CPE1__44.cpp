#include <bits/stdc++.h>
using namespace std;

int n,m;
bool cmp(int x,int y){
    if((x%m)!=(y%m)) return (x%m)<(y%m);
    else{
         if((x%2)*(y%2)) return x>y;
         else if((x%2==0)&&(y%2==0))  return x<y;
         else return x%2;
    }
}


int main(){

    while(cin>>n>>m){
        if(n==0&&m==0){
            cout<<"0 0\n";
            break;
        }
        cout<<n<<" "<<m<<endl;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a,a+n,cmp);
        for(int i=0; i<n; i++) cout<<a[i]<<endl;
    }
    return 0;
}
