class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ans(nums.size());
        vector<int> v(nums);
        sort(v.begin(), v.end());
        vector<int> dp(v[v.size()-1]+1, 0);
        for(int i = v.size()-1, idx = 1; i >= 0; i--){
            dp[v[i]] = idx;
            idx++;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(dp[nums[i]] == 1){
                ans[i] = "Gold Medal";
            }
            else if(dp[nums[i]] == 2){
                ans[i] = "Silver Medal";
            }
            else if(dp[nums[i]] == 3){
                ans[i] = "Bronze Medal";
            }
            else{
                ans[i] = to_string(dp[nums[i]]);
            }
        }
        return ans;
    }
};