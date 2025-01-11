#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;

  while(cin>>n){
    int k=0;
    int a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];
   }

    int b[n-1];
    for(int i=1;i<n;i++){
    b[i-1]=abs(a[i]-a[i-1]);
   }

   sort(b,b+(n-1));
   for(int i=0;i<n-1;i++){
     if(b[i]!=i+1) {
        cout<<"Not jolly"<<endl;
        k=1;
        break;
      }
   }
   if(k==0) cout<<"Jolly"<<endl;
  }
 return 0;
}
/*---------------------------------------------*/
#include <iostream>
#include <cstring>
using namespace std;
 int d[100];
int main() {
    int n;
    while (cin >> n){
        int pre, now;
         // initial value not guanranteed to be zero
        for (int i = 0; i < n; i++) {
            d[i] = 0;
        }
        cin >> pre;
        for (int i = 1; i < n; i++){
            cin >> now;
            d[abs(now - pre)]++;
            pre = now;
        }
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (d[i] != 1) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
    return 0;
}
//開某個陣列來記錄某差值出現過了沒
