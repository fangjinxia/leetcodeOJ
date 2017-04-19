class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(59, 0);
        //初始化基本
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i; j++){
                dp[i] = max(max(dp[i], j*(i-j)), j*dp[i-j]);
                
            }
        }
        return dp[n];
    }
};