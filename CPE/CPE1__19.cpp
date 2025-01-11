#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    int i=0;
    while(cin>>n){
            int u=0;
        i++;
       cout<<i<<". ";
       if(n==0) cout<<"0"<<endl;
        if(n>=pow(10,14)){
                u=1;
            cout<<int(n/pow(10,14));
            cout<<" kuti ";
            n-=int(n/pow(10,14))*pow(10,14);
        }
        if(n>=pow(10,12)){
                u=1;
              cout<<int(n/pow(10,12));
            cout<<" lakh ";
            n-=int(n/pow(10,12))*pow(10,12);
        }
        if(n>=pow(10,10)){
                u=1;
              cout<<int(n/pow(10,10));
            cout<<" hajar ";
            n-=int(n/pow(10,10))*pow(10,10);
        }
        if(n>=pow(10,9)){
                u=1;
               cout<<int(n/pow(10,9));
                cout<<" shata ";
            n-=int(n/pow(10,9))*pow(10,9);
        }
        if(n>=pow(10,7)){
              u=1;
                    cout<<int(n/pow(10,7))<<" ";
        
           
            n-=int(n/pow(10,7))*pow(10,7);
        }
         if(u==1) cout<<"kuti ";
        if(n>=pow(10,5)){
              cout<<int(n/pow(10,5));
            cout<<" lakh ";
            n-=int(n/pow(10,5))*pow(10,5);
        }
        if(n>=pow(10,3)){
             cout<<int(n/pow(10,3));
            cout<<" hajar ";
            n-=int(n/pow(10,3))*pow(10,3);
        }
        if(n>=pow(10,2)){
              cout<<int(n/pow(10,2));
            cout<<" shata ";
            n-=int(n/pow(10,2))*pow(10,2);
        }
        if(n!=0) cout<<n;
        cout<<endl;

    }
    return 0;
}
/*-------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
int a[] = {10000000, 100000, 1000, 100};
string s[] = {"kuti", "lakh", "hajar", "shata"} ;
string ans;
string num2str(long long x) {
    string s = "";
    while(x) {
        s += '0' + (x%10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
void solve(long long x) {
  if(x >= a[0]) {
    solve(x/a[0]);
    ans += " " + s[0];
    x %= a[0];
  }
  for(int i = 0; i < 4; i++) {
    if(x >= a[i]) {
        ans += " " + num2str((x/a[i])) + " " + s[i];
        x %= a[i];
    }
  }
  if(x > 0) ans += " " + num2str(x);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long N;
  int Case = 1;
  while(cin >> N) {
    if(Case<10) cout << "   " << Case++ <<".";
    else cout << "  " << Case++ <<".";
    if(N == 0) cout << " 0\n"; 
    else {
        ans ="";
        solve(N);
        cout << ans <<'\n';
    }
  }
}
//記得0的特判
//記得每次ans重置
//id的空格注意
