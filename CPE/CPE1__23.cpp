#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
  if (a>b) swap(a,b);
  if(b%a==0)  return a;
  else return gcd(b%a,a);
}


int main(){
  int n;
  cin>>n;
  for(int j=0;j<n;j++){
    string s1,s2;
    cin>>s1>>s2;
    int sum1=0;
    int sum2=0;
    int s1l=s1.length();
    int s2l=s2.length();
    for(int i=0;i<s1l;i++){
        if (s1[i]=='1') sum1+=pow(2,s1l-i-1);
    }
    for(int i=0;i<s2l;i++){
        if (s2[i]=='1') sum2+=pow(2,s2l-i-1);
    }
    cout<<"Pair "<<"#"<<j+1<<": ";
    if (gcd(sum1,sum2)>=2) cout<<"All you need is love!"<<endl;
    else cout<<"Love is not all you need! "<<endl;

  }
  return 0;
}
/*---------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
  if(x > y) swap(x, y);
  if(y % x == 0) return x;
  else return gcd(y%x, x);
}
int main() {
  int n;
  cin >> n;
  string s1, s2;
  int id = 1;
  while(n--){
    cout << "Pair #" << id ;
    id++;
    cin >> s1 >> s2;
    int n1 = 0, n2 = 0;
    for(int i = 0; i < s1.size(); i++) {
      n1 *= 2;
      n1 += s1[i]-'0';
    }
    for(int i = 0; i < s2.size(); i++) {
      n2 *= 2;
      n2 += s2[i]-'0';
    }
    if(gcd(n1, n2) > 1) cout << ": All you need is love!\n";
    else cout << ": Love is not all you need!\n";
  }
}
//二進位字串轉十進位
