#include <bits/stdc++.h>
using namespace std;
int main(){
  string s[105];
  int x=0;
  int y=0;
  while(getline(cin,s[x])){
    y=max(y,(int)s[x].length());  //有幾列
    x++; //有幾行
  }
  for(int i=0; i<y; i++){
    for(int j=x-1; j>=0;j--){
         if(i>=s[j].length())
             cout<<" ";
         else
             cout<<s[j][i];
    }
    cout<<endl;
  }
}
//注意 i >= s[j].length的case

#include <bits/stdc++.h>
using namespace std;
string s[105];
int main(){
   int k = 0;
   int n = 0;
   while(getline(cin, s[k])){
     n = max(n, (int)s[k].size());
     k++;
   }
   for(int i = 0; i < n; i++){
     for(int j = k-1; j >= 0; j--){
       if(i >= s[j].size()) {
        if(j!=0)cout << " ";
       }
       else cout<<s[j][i];
       }
     cout<<'\n';
   }
  
}
