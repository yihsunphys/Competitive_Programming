#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   while(cin>>n){
        int a=n;
        int k=0;
   int c=0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
                c=1;
            cout<<n<<" is not prime."<<endl;
            break;
        }
    }
    if(c==0){
    vector <int> v;
    while(n>0){
    v.push_back(n%10);
    n/=10;
     }
    int b=0;
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        b+=v[i]*pow(10,i);
    }
     for(int i=2;i<=sqrt(b);i++){
        if(b%i==0){
            cout<<a<<" is prime."<<endl;
            k=1;
            break;
        }
    }
    if(k==0&&a!=b) cout<<a<<" is emirp."<<endl;
    else if(k==0&&a==b) cout<<a<<" is prime."<<endl;
    }
   }
  return 0;
}
/*----------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
bool prime[1000005];
int main() {
  
  for(int i = 2; i < 1000005; i++) {
    for(int j = 2; i * j < 1000005; j++) {
      prime[i * j] = true;
    }
  }
  string s, s2;
  int n1, n2;
  while(cin >> s) {
    cout << s;
    s2 = s;
    reverse(s.begin(), s.end());
    n1 = stoi(s);
    n2 = stoi(s2);
    if(!prime[n2]) {
      if(prime[n1] || s == s2) cout << " is prime.\n";
      else cout << " is emirp.\n";
    }
    else cout << " is not prime.\n";
  }
}
