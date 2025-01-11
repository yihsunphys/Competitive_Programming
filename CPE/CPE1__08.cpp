#include <bits/stdc++.h>
using namespace std;
int main(){
  int x;
  cin>>x;
  while(x--){
    string s;
    cin>>s;
    double n=0;
    double N=0;
    for(int i=0;i<s.size();i++){
      n+=int(s[i]-'0')*pow(10,(s.size()-i-1));
    }
    for(int i=0;i<s.size();i++){
    N+=int(s[i]-'0')*pow(16,(s.size()-i-1));
     }
  int b1=0;
  int b2=0;
  for(int i=31;i>=0;i--){
    if(n>=pow(2,i)){
         n-=pow(2,i);
         b1++;
        }
     if(n==0) break;
     }
   for(int i=31;i>=0;i--){
    if(N>=pow(2,i)){
         N-=pow(2,i);
         b2++;
        }
     if(N==0) break;
     }
     cout<<b1<<" "<<b2<<endl;
  }
  return 0;
}
/*------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while(n--) {
    int num;
    cin >> num;
    int dec = num, hex = 0;
    int mul = 1;
    while(num) {
      hex += (num%10) * mul;
      num /= 10;
      mul *= 16;
    }
    int cnt = 0;
    while(dec) {
      if(dec & 1) cnt++;
      dec >>= 1;
    }
    cout << cnt << " ";
    cnt = 0;
    while(hex) {
      if(hex & 1) cnt++;
      hex >>= 1;
    }
    cout << cnt << '\n';
  }
}
//記住算1的方法
