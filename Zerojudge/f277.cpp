#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define endl '\n'
/*-------------------------------------*/
struct student{
    string name;
    int cls;
    int num;
    string s;
};

bool cmp(student std1, student std2){
    if(std1.cls==std2.cls) return std1.num<std2.num;
    else return std1.cls<std2.cls;
}

int main(){
  int n;
  cin>>n;
  student a[100000];
  for(int i=0;i<n;i++){
      cin>>a[i].name>>a[i].cls>>a[i].num>>a[i].s;
  }
  sort(a,a+n,cmp);
  for(int i=0;i<n;i++){
      cout<<a[i].cls<<" "<<a[i].num<<" "<<a[i].name<<endl;
      cout<<a[i].s<<endl;
  }

}
