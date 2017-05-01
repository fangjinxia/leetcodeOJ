class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        if(s.length() == 0)
            return 0;
            
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        for(int k = 1; k < n; k++){
            for(int i = 0; i+k < n; i++){
                if(s[i] == s[i+k])
                    dp[i][i+k] = 2 + dp[i+1][i+k-1];
                else
                    dp[i][i+k] = max(dp[i][i+k-1], dp[i+1][i+k]);
            }
        }
        return dp[0][n-1];
           
    }
};