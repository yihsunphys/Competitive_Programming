class Solution {
    private:
        class MyQueue{
        public:
            deque<int> que;
            void pop(int val){
                if(!que.empty() && val == que.front()){
                    que.pop_front();
                }
            }
            int front(){
                return que.front();
            }
            void push(int val){
                while(!que.empty() && que.back() < val){
                    que.pop_back();
                }
                que.push_back(val);
            }
        };
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            MyQueue que;
            vector<int> result;
            for(int i = 0; i < k; i++){
                que.push(nums[i]);
            }
            result.push_back(que.front());
            for(int i = k; i < nums.size(); i++){
                que.pop(nums[i-k]);
                que.push(nums[i]);
                result.push_back(que.front());
            }
            return result;
        }
    };