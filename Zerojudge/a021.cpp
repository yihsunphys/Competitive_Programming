#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
/*---------------------------------------*/
void ini(string &a, string &b){
    while(a.size()<b.size()) a='0'+a;
    while(b.size()<a.size()) b='0'+b;
}
bool Bisbigger(string a, string b){
    if(a.size()==b.size()) return b[0]>a[0];
    else return b.size()>a.size();
}
void del(string &s){
    while(s[0]=='0') s.erase(0,1);
}

string add(string a, string b){
    ini(a,b);
    int temp;
    int carry=0;
    string s="";
    for(int i=a.size()-1;i>=0;i--){
        temp=(a[i]-'0')+(b[i]-'0'); 
        s+=(temp+carry)%10+'0';
        if(temp+carry>9) carry=1;
        else carry=0;
    }
    if(carry) s+='1';
    reverse(s.begin(),s.end());
    return s;
}
string sub(string a, string b){
    string s="";
    bool k=0;
    if(Bisbigger(a,b)) {
        swap(a,b);
        k=1;
    }
    int temp;
    ini(a,b);
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]<b[i]) {
            temp=10-(b[i]-'0')+(a[i]-'0');
            a[i-1]--;
        }
        else temp=(a[i]-'0')-(b[i]-'0');
        s+=temp+'0';
    }
    reverse(s.begin(),s.end());
    if(s.size()!=1) del(s);
    if(k) s='-'+s;
    return s;
} 
string mul(string a, string b){
    string s="0";
    for(int i=b.size()-1;i>=0;i--){
        int num=b[i]-'0';
        if(i!=b.size()-1) a+='0';
        for(int i=0;i<num;i++){
            s=add(s,a);
        }
    }
    return s;
}
string div(string a, string b){
    string s="0";
    if(Bisbigger(a,b)) return s;
    else{
        string tmp=b;
        string restmp="1";
        for(int i=1;i<(a.size()-b.size());i++){
            tmp+='0';
            restmp+='0';
        }
        ini(a,b);
        while(a>=b){
            ini(a,tmp);
            if(a>=tmp) {
                a=sub(a,tmp);
                s=add(s,restmp);
            }
            else{
                tmp.erase(tmp.size()-1);
                restmp.erase(restmp.size()-1);
            }
            ini(a,b); 
        } 
        return s;  
    }   
}



int main(){
    string a,b;
    char c;
    cin>>a>>c>>b;
    if(c=='+') cout<<add(a,b)<<endl;
    if(c=='-') cout<<sub(a,b)<<endl;
    if(c=='*') cout<<mul(a,b)<<endl;
    if(c=='/') cout<<div(a,b);
}
