#include <bits/stdc++.h>
using namespace std;
int fib(int n){
    int F[n+1];
    F[0]=0;
    F[1]=1;
    if(n<2) return F[n];
    else{
        for(int i=2;i<=n;i++){
            F[i]=F[i-1]+F[i-2];
        }
        return F[n];
    }
}



int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    cout<<x<<" "<<"="<<" ";
    int z=0;
    int y=0;
    int a[100];
    for(int j=100;j>0;j--){
        if(x>=fib(j))  {
           //  cout<<"超過fib"<<j<<" ";
             y=j-1; //y為位數
             break;
        }
    }
    int j=y;
    while(j>0){
        if(x>=fib(j+1)){
            a[z]=1;
            x-=fib(j+1);
            if(j!=1) a[z+1]=0;
            z+=2;
            j-=2;
        }
        else{
            a[z]=0;
            z++;
            if(j==0) break;
            j--;
        }
    }


    for(int i=0;i<y;i++){
        cout<<a[i];
    }
    cout<<" (fib)"<<endl;
  }
 return 0;
}
/*----------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
int fibo[1005];
int main() {
  fibo[0] = 0;
  fibo[1] = 1;
  for(int i = 2; i <= 1005; i++)
    fibo[i] = fibo[i-1] + fibo[i-2];
  
  int n;
  cin >> n;
  while(n--) {
    int num;
    cin >> num;
    cout << num <<" = ";
    bool first = false;
    for(int i = 39; i>=2; i--) {
      if(num >= fibo[i]) {
        first = true;
        cout << "1";
        num -= fibo[i];
      }
      else {if(first) cout << "0";}
    }
    cout << " (fib)\n";
  }
}
// 從 fibo[39] 開始
