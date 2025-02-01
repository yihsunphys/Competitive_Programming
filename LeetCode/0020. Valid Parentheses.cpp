class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        for(auto it: s){
            if(it == '(' || it == '[' || it == '{')
                stk.push(it);
            else{
                if(it == ')'){
                    if(stk.empty() || stk.top()!='(') return false;
                    stk.pop();
                }
                if(it == ']'){
                    if(stk.empty() || stk.top()!='[') return false;
                    stk.pop();
                }
                if(it == '}'){
                    if(stk.empty() || stk.top()!='{') return false;
                    stk.pop();
                }
            }
        }
        if(stk.empty()) return true;
        else return false;
    }
};