//动态规划
//dp[n][k]表示1...n的排列中有k个pairs的个数
//Thus (n+1,k) equals (n,k)+(n,k-1)+(n,k-2)+.....+（n,k-n）
class Solution {
public:
    int kInversePairs(int n, int k) {
        int MOD = 1000000007;
        vector<vector<long long>> dp(n, vector<long long>(k+1));
        dp[0][0] = 1;
        for(int i = 1; i < n; ++i){
            for(int j = 0; j <= k; ++j){
                for(int m = j; m >= 0 && m >= (j-i); --m){
                    dp[i][j] += dp[i-1][m];
                }
                dp[i][j] %= MOD;
            }
        }
        
        return (int)dp[n-1][k];
    }
};