class Solution {
public:
    int upper_bound(vector<pair<int,int>> a, int begin, int end, int key) {
      int first = begin, last = end-1;
      int middle, pos = begin;       
      while(first < last){
        middle = (first+last)/2;
        if(a[middle].first < key){ 
            first = middle + 1;   pos = first;  
        }
        else{
            last = middle;     pos = last;                  
        }
      }
      if(a[pos].first == key) return pos;
      else return -1;
    }    
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<pair<int,int>> myvec;
      int l = nums.size();
      for(int i = 0; i < l; i++) {
        myvec.push_back({nums[i], i});
      }
      sort(myvec.begin(), myvec.end());
      //for(auto it: myvec) cout << it.first << it.second << '\n';
      int i;
      for(i = 0; i < l-1; i++) {
        int ans = upper_bound(myvec, i+1, l, target-myvec[i].first);
        if(ans != -1) return {myvec[i].second, myvec[ans].second};
      }
      return {-1, -1};
    }
};
//先sort 然後二分搜 但超慢 比暴搜還慢