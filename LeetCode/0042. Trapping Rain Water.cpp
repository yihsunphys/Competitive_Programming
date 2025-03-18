class Solution {
    public:
        int trap(vector<int>& height) {
            stack<int> stk;
            stk.push(0);
            int sum = 0;
            for(int i = 1; i < height.size(); i++){
                if(height[i] < height[stk.top()]){
                    stk.push(i);
                }
                else if(height[i] == height[stk.top()]){
                    stk.pop();
                    stk.push(i);
                }
                else {
                    while(!stk.empty() && height[i] > height[stk.top()]){
                        int m = stk.top();
                        stk.pop();
                        if(!stk.empty()){
                            int h = min(height[stk.top()], height[i]) - height[m];
                            int w = i-stk.top()-1;
                            sum += h*w;
                        }
                    }
                    stk.push(i);
                }
            }
            return sum;
        }
    };