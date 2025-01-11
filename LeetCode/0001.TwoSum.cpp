class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<pair<int,int>> myvec;
      int l = nums.size();
      for(int i = 0; i < l; i++) {
        myvec.push_back({nums[i], i});
      }
      sort(myvec.begin(), myvec.end());
      int index1 = 0;
	  int index2 = myvec.size() - 1;
      int sum;
      vector<int> answer;
        while(index1 < index2) {
            sum = myvec[index1].first + myvec[index2].first;
            
	    if(sum == target)
                break;
            else if(sum < target)
                index1++;
            else
                index2--;
        }
        
        answer.push_back(myvec[index1].second);
        answer.push_back(myvec[index2].second);
        
        return answer;
    }
};
//比較快的方法