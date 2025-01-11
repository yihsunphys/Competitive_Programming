#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define endl '\n'
/*------------------9.2s-------------------*/
int a[10],n;
bool visit[20];
void dfs(int i){
    if(i==n){
        for(int i=0;i<n;i++){
            if(i==n-1) printf("%d", a[i]); //cout<<a[i];
            else printf("%d ", a[i]); //cout<<a[i]<<" ";
        }
        printf("\n"); //cout<<endl;
    }
    else{
        for(int j=1;j<=n;j++){
            if(visit[j]) continue; //如果元素i已經填過就填下一個
            visit[j]=true;
            a[i]=j;
            dfs(i+1);
            visit[j]=false;
        }
    }
}

int main(){
    scanf("%d",&n);//cin>>n;
    dfs(0);
    return 0;
}
/*---------------------0.7s------------------------------------*/
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define endl '\n'
/*-------------------------------------*/
char a[10],n;
bool visit[20];
void dfs(int i){
    if(i==n)  puts(a);
    else{
        for(int j=1;j<=n;j++){
            if(visit[j]) continue; //如果元素i已經填過就填下一個
            visit[j]=true;
            if(j==10) {a[i*2]='1';a[i*2+1]='0';a[i*2+2]=' ';}
            else{
                if(!visit[10]){
                    a[i*2]=j+'0';
                    a[i*2+1]=' ';
                }
                else{
                    a[i*2+1]=j+'0';
                    a[i*2+2]=' ';
                }
            }
            dfs(i+1);
            visit[j]=false;
        }
    }
}
int main(){
    scanf("%d",&n);//cin>>n;
    dfs(0);
    return 0;
}
