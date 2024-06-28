#include <bits/stdc++.h>
using namespace std;
int doom[]={-1,10,21,7,4,9,6,11,8,5,10,7,12};
string date[]={"Monday","Tuesday", "Wednesday","Thursday", "Friday", "Saturday", "Sunday"};


int main(){
    int n, m, d;
    cin>>n;
    while(n--){
        cin>>m>>d;
        cout<<date[(d-doom[m]+35)%7]<<endl;
    }
    return 0;
}
