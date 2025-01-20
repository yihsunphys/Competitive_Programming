// easy
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for(auto i: asteroids){
            if(i>0) stk.push_back(i);
            else{
                bool p = true;
                while(!stk.empty() && stk.back()>0 && stk.back()<-1*i){
                    stk.pop_back();
                }
                if(stk.empty() || stk.back()<0) stk.push_back(i);
                if(!stk.empty() && stk.back()==-1*i)  stk.pop_back();
            }
        }
        return stk;
    }
};