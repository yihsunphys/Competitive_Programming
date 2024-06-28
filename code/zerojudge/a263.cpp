#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define endl '\n'
/*----------------------------*/
//先判斷是否閏年
bool c(int y){
   if(y%4==0){
      if(y%100==0){
         if(y%400==0) return 1;
         else return 0;
      }
      else return 1;
   }
   else return 0;
}

int main(){IOS;
  int y1,y2,m1,m2,d1,d2;
  while(cin>>y1>>m1>>d1>>y2>>m2>>d2){
   map<int,int> mp;
   mp[1]=31;mp[2]=28;mp[3]=31;mp[4]=30;mp[5]=31;mp[6]=30;
   mp[7]=31;mp[8]=31;mp[9]=30;mp[10]=31;mp[11]=30;mp[12]=31;
   int s1=d1,s2=d2;
   for(int i=0;i<y1;i++){
      s1+=365;
      if(c(i)) s1++;
   }
   for(int i=1;i<m1;i++){
         s1+=mp[i];
   }
   if(c(y1)&&m1>2) s1++;
   for(int i=0;i<y2;i++){
      s2+=365;
      if(c(i)) s2++;
   }
   for(int i=1;i<m2;i++){
         s2+=mp[i];
   }
   if(c(y2)&&m2>2) s2++;
   cout<<abs(s2-s1)<<endl;
  }
}
