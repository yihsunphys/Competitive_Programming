#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long
#define endl '\n'
/*---------------------------------------------------------*/
void prime(int n){
   string s=""; vector<int> v; vector <int> v2;
   for(int i=2;i<=n;i++){
      //if(n==1) break;
      int cnt=1;
      if(n%i==0){
         v.push_back(i);
         n/=i;
         while(n%i==0){
            cnt++;
            n/=i;
         }
         v2.push_back(cnt);
      }
   }
   reverse(v.begin(), v.end());
   reverse(v2.begin(),v2.end());
   for(int i=0; i<v.size(); i++){
      s+=to_string(v[i])+" "+to_string(v2[i])+" ";
   }
   //return s; 
   cout<<s<<endl;
 }
int main() {
    string s;
    stringstream ss;
    int p, e, num;
     
    while (getline(cin, s)) {
        if (s == "0") break;
        ss.clear();
        ss.str(s);
        num = 1;
        while (ss >> p >> e) {
            num *= (int)pow(p, e);
        }
        num--;
        //cout<<num;
        prime(num);
    }
    return 0;
}
 /*int main(){
    stringstream ss;
    string s;
    int a,b,num;
    while(getline(cin,s)){
       if(s=="0") break;
       ss.clear();
       ss.str(s);
       num=1;
       while(ss>>a>>b){
          num*=(int)pow(a,b);
       }
       cout<<num<<" ";
      num--;
      cout<<num<<" ";
      prime(num);
    }
    return 0;
 }*/
