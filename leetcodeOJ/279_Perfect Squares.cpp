class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            int k = INT_MAX;
            for(int j = 1; j*j <= i; j++){
                k = min(k, dp[i-j*j]+1);
            }
            dp[i] = k;
        }
        return dp[n];
    }
};