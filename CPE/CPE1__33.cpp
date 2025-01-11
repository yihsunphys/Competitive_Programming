#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    map <string, int> mp;
    getline(cin,s);
    while(n--){
        getline(cin,s);
        stringstream ss(s);
        ss>>s;
        mp[s]++;
    }
    for(auto i:mp){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}
/*---------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  string s;
  map <string, int> m;
  getline(cin,s);
  while(n--){
    
    getline(cin, s);
    stringstream ss(s);
    ss >> s;
    m[s]++;
  }
  for(auto it: m)
    cout<<it.first<<" "<<it.second<<'\n';
}
