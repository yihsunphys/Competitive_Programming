class Solution {
    public:
        int jump(vector<int>& nums) {
            int cover = 0;
            vector<int> minstep(nums.size(), INT_MAX);
            minstep[0] = 0;
            for(int i = 0; i <= cover; i++){
                if(i+nums[i] > cover){
                    for(int j = cover+1; j <= i+nums[i]; j++){
                        if(j<nums.size()) minstep[j] = min(minstep[i]+1, minstep[j]);
                    }
                }
                cover = max(i+nums[i], cover);
                if(cover >= nums.size()-1) break;
            }
            return minstep[nums.size()-1];
        }
    };

    class Solution {
        public:
            int jump(vector<int>& nums) {
                int cur = 0;
                int next = 0;
                int ans = 0;
                if(nums.size()==1) return 0;
                for(int i = 0; i < nums.size(); i++){
                    next = max(nums[i]+i, next);
                    if(i == cur){
                        cur = next;
                        ans++;
                        if(next>=nums.size()-1) break;
                    }
                }
                return ans;
            }
        };