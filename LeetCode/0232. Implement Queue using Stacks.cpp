class MyQueue {
public:
    stack<int> stk1, stk2;
    MyQueue() {

    }

    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        if(stk2.empty()) {
            while(!stk1.empty()){
                int tmp = stk1.top();
                stk2.push(tmp);
                stk1.pop();
            }
        }
        int x = stk2.top(); 
        stk2.pop();
        return x;  
    }
    
    int peek() {
        if(stk2.empty()) {
            while(!stk1.empty()){
                int tmp = stk1.top();
                stk2.push(tmp);
                stk1.pop();
            }
        }
        return stk2.top();
    }
    
    bool empty() {
        return (stk1.empty()&&stk2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */