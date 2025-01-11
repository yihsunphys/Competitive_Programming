#include <iostream>
using namespace std;
#define endl '\n'
/*-------------------------------------------*/
template<class T>
class stack{
    public:
      stack(int stackcapacity=10);
      bool empty() const;
      T top() const;
      void push(const T x);
      void pop();
    private:
      T *stk; //一個指標類型的陣列
      int tp;
      int capacity;
};
/*-------------------------------------------*/
template<class T>
stack<T>::stack(int stackcapacity): capacity(stackcapacity){
  //冒號代表順便給成員變量賦值 
    stk=new T[capacity];
    tp=-1;
}
//bool函數 
template<class T> 
inline bool stack<T>::empty() const{
    return tp==-1;   //代表top==-1時回傳true
}
//Top函數
template<class T>
inline T stack<T>::top() const{
    return stk[tp];
}
//push函數
template<class T>
void stack<T>::push(const T x){
    stk[++tp]=x;
}

template<class T>
void stack<T>::pop(){
    stk[tp--].~T();
}

int main(){
    stack<int> stk;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(x==1){
            int num;
            cin>>num;
            stk.push(num);
        }
        if(x==2){
            if(stk.empty()) cout<<-1<<endl;
            else cout<<stk.top()<<endl;
        }  
        if(x==3){
            if(!stk.empty()) stk.pop();
        } 
    }
}
