class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //int n = nums.size();
        vector<int> v(target+1, 0);
        v[0] = 1;
        for(int j = 0; j < v.size(); j++){
            for(int i = 0; i < nums.size(); i++){
                if(j >= nums[i])
                    v[j] += v[j-nums[i]];
            }
        }
        
        return v[target];
    }
};