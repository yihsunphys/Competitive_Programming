// 由小到大
class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            stack<int> stk;
            int result = 0;
            heights.insert(heights.begin(), 0);
            heights.push_back(0); 
            stk.push(0);
            for(int i = 1; i < heights.size(); i++){
                if(heights[i] > heights[stk.top()]){
                    stk.push(i);
                }
                else if(heights[i] == heights[stk.top()]){
                    stk.pop();
                    stk.push(i);
                }
                else {
                    while(!stk.empty() && heights[i] < heights[stk.top()]){
                        int h = heights[stk.top()];
                        stk.pop();
                        if(!stk.empty()){
                            int w = i-stk.top()-1;
                            result = max(result, h*w);
                        }
                    }
                    stk.push(i);
                }
            }
            return result;
        }
    };