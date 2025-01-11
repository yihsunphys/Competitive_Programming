#include <bits/stdc++.h>
using namespace std;

struct dictionary{
  char ch;
  int num;
}

dic[50]={{.ch='\0', .num=0}};  //dic[i]={.ch=, .num}
//建立一個空陣列

bool cmp(dictionary a , dictionary b){
  if (a.num==b.num)  return a.ch<b.ch;
  else  return a.num>b.num;
}

int main(){
  cin.tie(0);
  cout.sync_with_stdio(false);
  int n;
  cin>>n;
  n++;
  while(n--){
    string s;
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z'){
            dic[s[i]-'A'].num ++;
            dic[s[i]-'A'].ch=s[i];
        }
        else if(s[i]>='a'&&s[i]<='z'){
             dic[s[i]-'a'].num ++;
             dic[s[i]-'a'].ch=s[i]-'a'+'A';
        }
        else{
            continue;
        }
    }
  }
    sort(dic,dic+50,cmp);
    for (int i=0;i<50;i++){
        if (dic[i].num==0) break;
        cout<<dic[i].ch<<" "<<dic[i].num<<endl;
    }
  return 0;
}
//要寫struct
