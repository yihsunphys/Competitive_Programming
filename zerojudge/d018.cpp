#include <bits/stdc++.h>
using namespace std;
/*---------------------------------*/
int main(){
   string s;
   stringsream ss;
   while(getline(cin,s)){
      ss.clear(); //初始化
      ss.str(s);
      int n;
      double sum1=0; //奇數和
      double sum2=0; //偶數和
      while(ss>>n){ //輸入序號
         char c;
         ss>>c; //輸入冒號
         double x;
         ss>>x; //輸入浮點數
         if(n%2!=0) sum1+=x;
         if(n%2==0) sum2+=x; 
      }
      cout<<sum1-sum2<<endl;
   }
}
 
