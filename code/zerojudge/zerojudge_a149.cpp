#include<bits/stdc++.h>
using namespace std;
int to_int(char c){  //變成編碼
    return c-'0';
}
int main(){
    int x;
    cin>>x;
    while(x--){
        string a;
        cin>>a;
        int ans=1;
        for(char c:a){ //字串只能是"字元"陣列
            ans*=to_int(c);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
