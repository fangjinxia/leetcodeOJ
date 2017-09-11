class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        //注意n为0和1的情况
        if(n < 2)
            return n;
        
        vector<int> dp(n, 1);
        
        for(int i = 1; i < n; ++i){
            if(nums[i] > nums[i-1])
                dp[i] = dp[i-1] + 1;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};