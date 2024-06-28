#include <bits/stdc++.h>
using namespace std;

int n, num;
char a[30];
void dfs(int now, int left, int right){
  if(left>n||right>left) return;
  if(now==num){
     a[num]='\0';
     cout<<a<<"\n";
    return;
  }

  a[now]='(';
  dfs(now+1, left+1, right);
  a[now]=')';
  dfs(now+1, left, right+1);

}


int main(){
    while(cin>>n){
        num=2*n;
        dfs(0, 0, 0);
        cout<<"\n";
    }
    return 0;
}
