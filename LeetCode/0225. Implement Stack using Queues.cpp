class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size = q.size()-1;
        int x;
        while(size--){
            x = q.front();
            q.pop();
            q.push(x);
        }
        x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        int size = q.size()-1;
        int x;
        while(size--){
            x = q.front();
            q.pop();
            q.push(x);
        }
        x = q.front();
        q.pop();
        q.push(x);
        return x;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */