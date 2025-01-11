#include <bits/stdc++.h> 
using namespace std;
/*--------------------------*/
//先轉postfix後運算
int main(){
  map <string,int> mp;
  mp["+"]=1; mp["-"]=1; mp["*"]=2; mp["/"]=2;mp["%"]=2;mp["("]=0;
  stack <string> stk; 
  vector<string> v ;
  string s;
  while(getline(cin,s)){
     stringstream ss;
     ss<<s;
     string c;
     while(ss>>c){
        bool k=0;
        for(int i=0;i<c.size();i++){
           if(!isdigit(c[i])) k=1;
        }
        if(!k) v.push_back(c);
        else if(c=="(") stk.push(c);
        else if(c==")") {
           while(stk.top()!="("){
              v.push_back(stk.top());
              stk.pop();
           }
           stk.pop();
        }
        else{
           if(!stk.empty()){
            while(!stk.empty()&&mp[c]<=mp[stk.top()]){
               v.push_back(stk.top());
               stk.pop();
            }
           }
           stk.push(c);
        }
      }
      while(!stk.empty()){
         v.push_back(stk.top());
         stk.pop();
      }
   stack<int> stk2;
   for(int i=0;i<v.size();i++){
            bool k=0;
            for(int j=0;j<v[i].size();j++){
               if(!isdigit(v[i][j])) k=1;
            }
            if(!k){
                stk2.push(stoi(v[i]));
            }
            else if(v[i]=="+"){
                int a=stk2.top();stk2.pop();
                int b=stk2.top();stk2.pop();
                int ans=a+b;stk2.push(ans);
            }
            else if(v[i]=="-"){
                int a=stk2.top();stk2.pop();
                int b=stk2.top();stk2.pop();
                int ans=b-a;stk2.push(ans);
            }
            else if(v[i]=="*"){
                int a=stk2.top();stk2.pop();
                int b=stk2.top();stk2.pop();
                int ans=a*b;stk2.push(ans);
            }
            else if(v[i]=="/"){
                int a=stk2.top();stk2.pop();
                int b=stk2.top();stk2.pop();
                int ans=b/a;stk2.push(ans);
            }
            else if(v[i]=="%"){
                int a=stk2.top();stk2.pop();
                int b=stk2.top();stk2.pop();
                int ans=b%a;stk2.push(ans);
            }
        }
        cout<<stk2.top()<<endl;
   }  
}
