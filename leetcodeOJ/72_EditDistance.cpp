//动态规划
//递推式：
// dp[i][0] = i;
// dp[0][j] = j;
// dp[i][j] = dp[i - 1][j - 1], if word1[i - 1] = word2[j - 1];
// dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1), otherwise.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if(m == 0)
            return n;
        if(n == 0)
            return m;
        int ans[n+1][m+1] = {0};
        for(int i = 0; i <= n; i++){
            ans[i][0] = i;
        }
        for(int j = 0; j <= m; j++){
            ans[0][j] = j;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]){
                    ans[i][j] = ans[i-1][j-1];
                }
                else{
                    ans[i][j] = min(min(ans[i-1][j-1], ans[i][j-1]), ans[i-1][j]) + 1;
                }
            }
        }
        return ans[n][m];
    }
};