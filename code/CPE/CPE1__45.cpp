#include <bits/stdc++.h>
using namespace std;
int fnc(string s){
     int sum=0;
    for(int i=0; i<s.size(); i++){
        sum+=int(s[i]-'0');
    }
    if(sum<10) return sum;
    else return fnc(to_string(sum));
}


int main(){
    string s;
    while(cin>>s){
         if(s=="0")  break;   
        cout<<fnc(s)<<endl;
    }
    return 0;
}
