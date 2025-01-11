#include <bits/stdc++.h>
using namespace std;
/*------------------------*/

map<char,int> mp;
int main(){
    mp['I']=1;mp['V']=5;mp['X']=10;mp['L']=50;
    mp['C']=100;mp['D']=500;mp['M']=1000;
    string s;
    while(getline(cin,s)){
        if(s=="#") break;
        stringstream ss(s);
        string s1,s2;
        ss>>s1>>s2; //cout<<s1<<s2;
        int sum1=0,sum2=0;
        for(int i=0;i<s1.size();i++){
            if(i!=0&&mp[s1[i]]>mp[s1[i-1]]) {
                sum1+=mp[s1[i]]-2*mp[s1[i-1]];
            }
            else sum1+=mp[s1[i]]; //cout<<sum1<<" ";
        }
        for(int i=0;i<s2.size();i++){
            if(i!=0&&mp[s2[i]]>mp[s2[i-1]]) {
                sum2+=mp[s2[i]]-2*mp[s2[i-1]];
            }
            else sum2+=mp[s2[i]]; //ˇcout<<sum2;
        }
        int sol=sum1-sum2;
        if(sol<0) sol=-sol;
        if(sol==0){cout<<"ZERO\n";continue;}
        while(sol>=1000){cout<<"M";sol-=1000;}
        if(sol>=900){cout<<"CM";sol-=900;}
        if(sol>=500){cout<<"D";sol-=500;}
        if(sol>=400){cout<<"CD";sol-=400;}
        while(sol>=100) {cout<<"C";sol-=100;}
        if(sol>=90) {cout<<"XC";sol-=90;}
        if(sol>=50) {cout<<"L";sol-=50;}
        if(sol>=40) {cout<<"XL";sol-=40;}
        while(sol>=10) {cout<<"X";sol-=10;}
        if(sol>=9) {cout<<"IX";sol-=9;}
        if(sol>=5) {cout<<"V";sol-=5;}
        if(sol>=4) {cout<<"IV";sol-=4;}
        while(sol>0) {cout<<"I";sol--;}
        cout<<endl;
    }
}
