#include <bits/stdc++.h>
using namespace std;
/*---------------------------------*/
int main(){
   string s;
   stringstream ss;
   while(getline(cin,s)){ //一次讀一整行
      int ans=0;
      ss.clear(); //初始化
      ss.str(s);  //讀入stringstream
      string s2;
      while(ss>>s2){ //以空白分割字串
         bool k=1;
         //檢查字串是否為純數字
         for(int i=0;i<s2.size();i++){
            if(isdigit(s2[i])) {
               k=1; 
               }
            else {
               k=0;
               break; 
            }
         }
         //如果是 把字串轉為int並加到ans
         if(k) ans+=stoi(s2);
      }
      cout<<ans<<endl;
   }
}
