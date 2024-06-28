#include <bits/stdc++.h>
using namespace std;
int le(int n){
  int k=0;
  while(1){
    if(n==1) {
            k++;
            return k;
            break;
    }
    else{
      if(n%2!=0){
          n=3*n+1;
          k++;
     }
      else{
        n=n/2;
        k++;
      }
    }
  }
}

int main(){
   int a,b;
   while(cin>>a>>b){    
    int d=0;
    int x=abs(a-b)+1; 
    int c[x];
    for(int i=min(a,b);i<=max(a,b);i++){
        c[d]=le(i);
        d++;
    }
    cout<<a<<" "<<b<<" "<< *max_element(c,c+x)<<endl;
   }
   return 0;
}

#include <bits/stdc++.h>
using namespace std;
int alg(int x){
int cnt= 0;
  while(x !=1){
    cnt++;
    if(x%2 == 0){
      x /= 2;
    }
    else x = 3*x+1; 
  }
  return cnt+1;
}

int main(){
  int i, j;
  
  while(cin >> i >> j){
  cout << i <<" "<< j<<" ";
    int ans = 0;
    if(i>j) swap(i,j);
    for(int k = i; k <= j; k++){
      ans = max(ans, alg(k));
    }
    cout<<ans<<'\n';
  }
}
