#include <iostream>
using namespace std;
int main(){
 int x,y,i,j,a[105][105];  
 while(cin>>x>>y){
  for(i=0;i<x;i++){
    for(j=0;j<y;j++){  
      cin>>a[i][j];
    }
  }
  for(i=0;i<y;i++){
    for(j=0;j<x;j++){  
      cout<< a[j][i]<<" " ;
    }
    cout<<endl;
  }
 }
 return 0;
}
