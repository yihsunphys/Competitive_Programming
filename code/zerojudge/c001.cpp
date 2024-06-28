#include <bits/stdc++.h>
using namespace std;
/*------------------------------------*/
char len[1005][1005];
int n1, n2;
string s1,s2;
int lcs(int n1, int n2){
  for(int i=0; i<=n1; i++) len[i][0]=0;
  for(int j=0; j<=n2; j++) len[0][j]=0; 
  for(int i=1;i<=n1;i++){
      for(int j=1;j<=n2;j++){
          if(s1[i]==s2[j]) len[i][j]=len[i-1][j-1]+1;
          else len[i][j]=max(len[i-1][j], len[i][j-1]);
      }
  }
  return len[n1][n2];
}

int main(){
  while(cin>>s1>>s2){
  n1=s1.size();
  n2=s2.size();
  s1='0'+s1; s2='0'+s2;    
  cout<<lcs(n1, n2)<<endl;
  }

}
