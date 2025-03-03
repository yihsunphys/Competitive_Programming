// i从0开始累加rest[i]，和记为curSum，一旦curSum小于零，说明[0, i]区间都不能作为起始位置
class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int start = 0;
            int cur = 0, tot = 0;
            for(int i = 0; i < gas.size(); i++){
                cur+=gas[i]-cost[i];
                if(cur<0){
                    cur = 0;
                    start = i+1;
                }
                tot+=gas[i]-cost[i];
            }
            if(tot<0) return -1;
            else return start;
        }
    };