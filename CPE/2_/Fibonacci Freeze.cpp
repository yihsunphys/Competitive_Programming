#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long 
#define endl '\n' 
/*-----------------------------------*/
string bigsum(string s1, string s2){
   string s;//="";
   int n1=s1.length(), n2=s2.length();
   int carry=0;
   for(int i=0;i<n2;i++){
      int tmp=carry+(s1[i]-'0')+(s2[i]-'0');
      s+='0'+tmp%10;
      carry=tmp/10;
   }
   if(n1==n2){
     if(carry)  s+='0'+carry;
   }
   else{
      s+='0'+(carry+(s1[n1-1]-'0'));
   }
   return s;
}

string f[5000];
int main(){

   f[0]="0";
   f[1]="1";
   for(int i=2;i<=5000;i++){
      f[i]=bigsum(f[i-1],f[i-2]);
   }
   int n;
   while(cin>>n){
      string s=f[n];
      reverse(s.begin(),s.end());
   cout<<"The Fibonacci number for "<<n<<" is "<<s<<endl;
   }
}
