#include <bits/stdc++.h> //此題數字字串轉整數陣列
using namespace std;
/*size(char s[105])
{
      int i;
      for(i=0;i<105;i++){
        if (s[i]==(int)'\0'){
          break;
        }
        i++;
     }
     return i;
}*/

int main(){
  char s[1001];
  int a[1001];
  cin.getline( s, 1001 );
  for(int i=0;i<strlen(s);i++) //length
  {
        a[i]=s[i]-(int)'0';
  }
  int b,c,sum,sum1;
  b=0;c=0;sum=0;sum1=0;
  for(int j=1;j<=strlen(s);j++){
    if((strlen(s)-j+1)%2==0)    //偶數
        sum+=a[j-1];
    else
        sum1+=a[j-1];
  }
  //cout<<sum<<endl;cout<<sum1<<endl;
  cout<<abs(sum-sum1);
  return 0;
}
