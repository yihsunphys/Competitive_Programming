#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct cat{
    string name;
    string job;
    ll age; 
};
map<string, int> mp;
bool cmp(cat cat1, cat cat2){
  if(cat1.job == cat2.job) {
    if(cat1.age == cat2.age) return cat1.name < cat2.name;
    if(cat1.job == "appentice") return cat1.age < cat2.age;
    else return cat1.age > cat2.age;
  }
  else return mp[cat1.job] < mp[cat2.job];
}
cat a[10005];
int main() {
  mp["elder"] = 0; mp["nursy"] = 1; mp["kit"] = 2;
  mp["warrior"] = 3; mp["appentice"] = 4;
  mp["medicent"] = 5; mp["deputy"] = 6; mp["leader"] = 7;
  int n, m;
  while(cin >> n >> m){
    for(int i = 0; i < n; i++) {
      cin >> a[i].name >> a[i].job >> a[i].age;
    }
    sort(a, a + n, cmp);
    for(int i = 0; i < min(m,n); i++) {
      cout << a[i].name << '\n';
    }
  }
}