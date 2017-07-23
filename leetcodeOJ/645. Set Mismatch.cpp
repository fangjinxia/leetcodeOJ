class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v(nums.size()+1, 0);
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            ++v[nums[i]];
            if(v[nums[i]] > 1){
                ans.push_back(nums[i]);
                break;
            }
        }
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int ideal_sum = nums.size() * (nums.size()+1) / 2;
        int tmp = ideal_sum - sum + ans[0];
        ans.push_back(tmp);
        
        return ans;                
    }
};