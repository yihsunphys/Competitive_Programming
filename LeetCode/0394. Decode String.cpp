class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ']'){
                string tmp = "";
                while(stk.top()!="["){
                    tmp = stk.top() + tmp; stk.pop();
                }
                stk.pop();
                string time = "";
                while(!stk.empty()&&isdigit(stk.top()[0])){
                    time = stk.top() + time; stk.pop();
                }
                int count = stoi(time);
                string ret = "";
                while(count--) ret+=tmp;
                stk.push(ret);
            }  
            else stk.push(string(1, s[i]));
        }
        string ans = "";
        while(!stk.empty()){
            ans = stk.top()+ans;
            stk.pop();
        }
        return ans;
    }
};