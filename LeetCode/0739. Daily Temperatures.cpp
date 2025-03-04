class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            vector<int> ans(temperatures.size(), 0);
            stack<int> stk;
            stk.push(0);
            for(int i = 1; i < temperatures.size(); i++){
                if(temperatures[stk.top()] >= temperatures[i]){
                    stk.push(i);
                }
                else{
                    while(!stk.empty() && temperatures[stk.top()] < temperatures[i]){
                        ans[stk.top()] = i-stk.top();
                        stk.pop();
                    }
                    stk.push(i);
                }
            }
            return ans;
        }
    };