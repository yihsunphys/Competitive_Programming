#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int c=0;
    while(cin>>n){
        int b[n];
        int flag=0;
        for(int i=0; i<n; i++){
            cin>>b[i];
        }
        if(b[0]<1) flag=1;
         for(int i=1;i<n;i++){
        }

        int a[n*(n-1)/2+n];
        int k=0;
        for(int i=0; i<n; i++){
            for(int j=0;j<n;j++){
                if(i<=j) {
                        a[k]=b[i]+b[j];
                        k++;
                }
            }
        }
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(a[i]==a[j]&&i!=j) {
                        flag=1;
                }
            }
        }
       c++;
        cout<<"Case #"<<c<<": It is";
        if(flag==0) cout<<" a B2-Sequence.\n";
        else cout<<" not a B2-Sequence.\n";
        cout<<endl;
    }
    return 0;
}
/*---------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
int a[10005] = {};
int main() {
  int n;
  int id = 0;
  while(cin >> n){
    id++;
    bool flag = false;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      if(a[i]-a[i-1] <= 0 && i != 1) {
        flag = true;
        break;
      }
    }
    if(flag) cout<<"Case #"<<id<<": It is not a B2-Sequence.\n";
    else {
      set<int>s;
      int tmp = -1;
      for(int i = n; i > n/2; i--) {
        for(int j = n-i+1; j<i; j++) {
          if(a[i]+a[j] > tmp) {
            tmp = a[i] + a[n-i+1];
            break;
          }
          else if(a[j] + a[i] == tmp && i!=j){
             flag = true;
             break;
          }
          tmp = a[i] + a[n-i+1]; 
        }
        if(flag) break;
      }
      if(flag) cout<<"Case #"<<id<<": It is not a B2-Sequence.\n";
      else cout<<"Case #"<<id<<": It is a B2-Sequence.\n";
    }
    cout<<'\n';
  }
  
}
