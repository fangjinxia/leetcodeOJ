class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for(int i = 1; i <= n; i++){
            for(int lo = 1; lo <= n-i+1; lo++){
                int hi = lo+i-1;
                for(int k = lo; k <= hi;  k++){
                    dp[lo][hi] = max(dp[lo][hi], nums[lo-1]*nums[k]*nums[hi+1]+dp[lo][k-1]+dp[k+1][hi]);
                }
            }
        }
        
        return dp[1][n];
    }
};