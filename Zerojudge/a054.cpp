#include <bits/stdc++.h>
using namespace std;
/*------------------------------*/
int main(){
   map<int,char> mp;
   mp[10]='A';mp[11]='B';mp[12]='C';mp[13]='D';
   mp[14]='E';mp[15]='F';mp[16]='G';mp[17]='H';
   mp[18]='J';mp[19]='K';mp[20]='L';mp[21]='M';
   mp[22]='N';mp[23]='P';mp[24]='Q';mp[25]='R';
   mp[26]='S';mp[27]='T';mp[28]='U';mp[29]='V';
   mp[30]='X';mp[31]='Y';mp[32]='W';mp[33]='Z';
   mp[34]='I';mp[35]='O';
   string s;
   cin>>s;
   int c=s[8]-'0';
   if(c==0) c=10;
   int sum=0;
   for(int i=0;i<8;i++){
     sum+=(s[i]-'0')*(8-i);
   }//cout<<sum;
   for(int i=10;i<=17;i++){
      if(10-(sum+i/10+i%10*9)%10==c) cout<<mp[i];
   }
      if(10-((sum+(34/10)+(34%10*9))%10)==c) cout<<mp[34];
   for(int i=18;i<=22;i++){
      if(10-((sum+(i/10)+(i%10*9))%10)==c) cout<<mp[i];
   }
   if(10-((sum+(35/10)+(35%10*9))%10)==c) cout<<mp[35];
   for(int i=23;i<=29;i++){
      if(10-((sum+(i/10)+(i%10*9))%10)==c) cout<<mp[i];
   }
   if(10-((sum+(32/10)+(32%10*9))%10)==c) cout<<mp[32];
   for(int i=30;i<=31;i++){
      if(10-((sum+(i/10)+(i%10*9))%10)==c) cout<<mp[i];
   }
   if(10-((sum+(33/10)+(33%10*9))%10)==c) cout<<mp[33];

}
