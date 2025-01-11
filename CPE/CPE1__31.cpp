#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s; 
    while(cin>>n){
         int a[]={1,2,6,5,3,4};
         if(n==0) break;
        while(n--){
                cin>>s;
           if(s=="north"){
                 int b=a[1];
                a[1]=a[0];
                a[0]=a[3];
                a[3]=a[2];
                a[2]=b;
           }
           if(s=="south"){
                int b=a[1];
                a[1]=a[2];
                a[2]=a[3];
                a[3]=a[0];
                a[0]=b;
           }
           if(s=="east"){
                int b=a[0];
                a[0]=a[4];
                a[4]=a[2];
                a[2]=a[5];
                a[5]=b;
           }
           if(s=="west"){
                int b=a[5];
               a[5]=a[2];
               a[2]=a[4];
               a[4]=a[0];
               a[0]=b;
           }
        }
        cout<<a[0]<<endl;
    }
    return 0;
}
/*---------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    while(cin >> n) {
        //上前下後西東
        int a[] = {1, 2, 6, 5, 4, 3};
        if(n == 0) break;
        while(n--) {
          cin >> s;
          if(s == "north") {
            int tmp = a[0]; a[0] = a[3]; a[3] = a[2];
            a[2] = a[1]; a[1] = tmp;
          }
          else if(s == "south") {
            int tmp = a[0]; a[0] = a[1]; a[1] = a[2];
            a[2] = a[3]; a[3] = tmp;
          }
          else if(s == "east"){
            int tmp = a[0]; a[0] = a[5]; a[5] = a[2];
            a[2] = a[4]; a[4] = tmp;
          }
          else if(s == "west") {
            int tmp = a[0]; a[0] = a[4]; a[4] = a[2];
            a[2] = a[5]; a[5] = tmp;
          }
        }
        cout << a[0] <<'\n';
    }
}
