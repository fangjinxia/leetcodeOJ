//¶¯Ì¬¹æ»®
// cost = min(k+ max( DP(start,k-1) + DP(k+1, end) ) )
class Solution {
public:
    int getMoneyAmount(int n) {
        if(n == 1)
            return 0;
        int dp[n+1][n+1]; 
        memset(dp, 0, sizeof(dp));
        
        for(int distance = 1; distance < n; distance++){
            for(int i = 0; i+distance <= n; i++){
                int j = i+distance;
                dp[i][j] = INT_MAX;
                for(int k = i; k <= j; k++){
                    dp[i][j] = min(dp[i][j], k+max((k==i)?0:dp[i][k-1], (k==j)?0:dp[k+1][j]));
                }
            }
        }
        
        return dp[1][n];
    }
};