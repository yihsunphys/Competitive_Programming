#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m){
        vector <int> v;
        int c=0;
        if(n==0||m==0) {
                c=1;
                }
        else{
        v.push_back(n);
        while(n>1){
         if(n%m!=0) {
                c=1;
                break;
              }
        n/=m;
        v.push_back(n);
        }
        }
        if(c==1) cout<<"Boring!"<<endl;
        else {
            for(auto i: v){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
}
/*----------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
int a[100];
int main() {
  int n, m;
  while(cin >> n >> m) {
    int idx = 0;
    while(n>1) {
      if(n%m != 0 || m==1) break;
      a[idx] = n;
      idx++;
      n /= m;
    }
    a[idx] = 1;
    if(n != 1 || m==1) cout<<"Boring!\n";
    else {
      for(int i = 0; i <= idx; i++)
        cout << a[i] <<" \n"[i == idx];
    }
  }
}
//要考慮m=1時要跳出迴圈
