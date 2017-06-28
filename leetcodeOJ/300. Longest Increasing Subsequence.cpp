class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return n;
        
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 1; i < n; ++i){
            dp[i] = 1;
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            //cout << dp[i] << endl;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};