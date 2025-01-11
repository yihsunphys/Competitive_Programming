#include <iostream>
using namespace std;
int main(){
  int x,i=2;
  cin>>x;
  
  while(i<=x){
    int count=1;
    if(x%i==0){
      x=x/i;
      cout<<i;
        
      while(x%i==0){
        count++;
        x=x/i;      
      }
      if (count!=1){
            cout<<"^"<<count;
      }
      if(x!=1){
        i++;
        cout<<" * ";
      }
    }
      else{
        i++;
      }
                      
  }
  return 0;
}
