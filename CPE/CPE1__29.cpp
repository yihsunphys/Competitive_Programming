#include <bits/stdc++.h>
using namespace std;
int main(){
  string a, b;
  while(getline(cin,a)){
    getline(cin,b);
    int alp1[26] = {};
    int alp2[26] = {}; 
    for(int i = 0; i < a.size(); i++)
      alp1[a[i]-'a']++;
    for(int i = 0; i < b.size(); i++)
      alp2[b[i]-'a']++;
    
    for(int i = 0; i < 26; i++){
      if(alp1[i] > 0 && alp2[i] >0){
        int num = min(alp1[i], alp2[i]);
        while(num--)
           cout << char(i+'a');
      }
    }
    cout<<'\n';
  }
}
