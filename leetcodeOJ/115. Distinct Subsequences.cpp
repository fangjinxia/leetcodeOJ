class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();//j
        int n = t.length();//i
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i <= m; ++i){
            dp[0][i] = 1;
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(s[j-1] == t[i-1]){
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        
        return dp[n][m];
    }
};