#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    string s;
    vector <int> v;

    while(cin>>x){
        getline(cin, s);
        getline(cin, s);
        stringstream ss(s);
        v.clear();
        while(ss>>s){
            v.push_back(stoi(s));
        }
        v.pop_back();
        reverse(v.begin(),v.end());
        int mul=1,ans=0;
        for(int i=0;i<v.size();i++){
            ans+=v[i]*(i+1)*mul;
            mul*=x;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*-------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
int a[100];
int main(){
  int x;
  string s;
  while(cin>>x){
    getline(cin,s);
    getline(cin,s);
    stringstream ss(s);
    int idx = 0;
    while(ss >> a[idx]){
      idx++;}
    idx--;
    int ans = 0;
    for(int i = 0; i < idx; i++){
      int tmp = (idx-i);  
      tmp *= a[i]; 
      if(idx-i-1>0){
      for(int j =0; j < idx-i-1; j++)
        tmp*=x;
      }
      ans += tmp;
    }
    cout<<ans<<'\n';
  }
}
