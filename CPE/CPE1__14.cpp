#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
     int a,  c;
     double b;
     cin>>a>>b>>c;
     double r;
     if(b==0){
        cout<<"0.0000\n";
        continue;
     }
     r=pow(1.0-b,a); //公比
     double x;  //首項
     x=b*pow(1.0-b,c-1);
     double ans;
     ans=x/(1.0-r);
     cout<<fixed<<setprecision(4)<<ans<<endl;
  }
  return 0;
}
/*------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while(n--) {
    int num, idx;
    
    double p;
    cin >> num >> p >> idx;
    double a1, r;
    a1 = pow((1-p), idx-1) * p;
    r = pow((1-p), num);
    if(r == 1) cout <<"0.0000\n";
    else
      cout << fixed << setprecision(4) << a1/(1-r) <<'\n';
  }
}
//注意r=1的case
