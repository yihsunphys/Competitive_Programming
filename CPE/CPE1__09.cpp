#include <bits/stdc++.h>
using namespace std;
void del(string &s1, string &s2){
  while(s1.size() != s2.size()){
    if(s1.size() > s2.size()) s2 = '0'+s2;
    else s1 = '0'+s1;
  }
}
int main(){
  string s1, s2;
  while(cin>>s1>>s2){
  int cnt = 0;
    if(s1 =="0" && s2 == "0") break;
    del(s1, s2);
    int carry = 0;
      for(int i = s1.size()-1; i>=0; i--){
      //cout<<i<<endl;
        int sum = int(s1[i]-'0') + int(s2[i]-'0') +carry; //cout<<sum;
        if (sum>9) {
          carry = 1;
          cnt++;
        }
        else carry = 0; 
      }
    if(cnt==0) printf("No carry operation.\n");
    else if(cnt==1) printf("%d carry operation.\n", cnt);
    else printf("%d carry operations.\n", cnt);
  }
}
/*-------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  while(cin >> a >> b) {
    if(a == 0 && b == 0) break;
    int carry = 0, cnt = 0;
    while(a || b) {
      if((a%10)+(b%10)+carry >= 10) {
        carry = 1; cnt++;
      }
      else carry = 0;
      a/=10; b/=10;
    }
    if(cnt == 0) cout << "No carry operation.\n";
    else if(cnt == 1) cout << "1 carry operation.\n";
    else cout << cnt << " carry operations.\n";
  }
}
