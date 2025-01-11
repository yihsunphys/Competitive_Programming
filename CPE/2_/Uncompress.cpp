#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long 
#define endl '\n'
/*-------------------------------------------*/
string s;
string word="";
int num=0;
vector <string> v;

void move(string w){
   v.push_back(v.back());
   for(int i=v.size()-2; i>0; i--) v[i]=v[i-1];
   v[0]=w;
}

void printword(){
   cout<<word;
   if(v.empty()) v.push_back(word);
   else move(word);
   word="";
}

void printnum(){
   string w=v[num-1];
   cout<<w;
   for(int i=num-1;i>0;i--) v[i]=v[i-1];
   v[0]=w;
   num=0;
}


int main(){IOS;
   while(getline(cin,s)){//一次讀一整行
      if(s=="0") break;
      s+="\n";
      //分為三種情況 數字 字母 其他(只要印)
     for(int i=0;i<s.size();i++){
         if(isalpha(s[i])){
            word+=s[i];
         }
         else if(isdigit(s[i])){
            num*=10;   //字串數字轉int
            num+=int(s[i]-'0');
         }
         else {
            if(num) printnum();
            if(word!="") printword();
            cout<<s[i];
         }
      }
   }
   return 0;
}
