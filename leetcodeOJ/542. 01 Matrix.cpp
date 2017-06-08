class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0)
                    dp[i][j] = 0;
                else{
                    if(i && dp[i-1][j] != INT_MAX && dp[i][j] > dp[i-1][j]+1)//ÍùÉÏ
                        dp[i][j] = dp[i-1][j]+1;
                    if(j && dp[i][j-1] != INT_MAX && dp[i][j] > dp[i][j-1]+1)//Íù×ó
                        dp[i][j] = dp[i][j-1]+1;
                    if(i<m-1 && dp[i+1][j] != INT_MAX && dp[i][j] > dp[i+1][j]+1)//ÍùÏÂ
                        dp[i][j] = dp[i-1][j]+1;
                    if(j<n-1 && dp[i][j+1] != INT_MAX && dp[i][j] > dp[i][j+1]+1)//ÍùÓÒ
                        dp[i][j] = dp[i][j-1]+1;
                }
            }
        }
        
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(matrix[i][j] == 0)
                    dp[i][j] = 0;
                else{
                    if(i && dp[i-1][j] != INT_MAX && dp[i][j] > dp[i-1][j]+1)//ÍùÉÏ
                        dp[i][j] = dp[i-1][j]+1;
                    if(j && dp[i][j-1] != INT_MAX && dp[i][j] > dp[i][j-1]+1)//Íù×ó
                        dp[i][j] = dp[i][j-1]+1;
                    if(i<m-1 && dp[i+1][j] != INT_MAX && dp[i][j] > dp[i+1][j]+1)//ÍùÏÂ
                        dp[i][j] = dp[i+1][j]+1;
                    if(j<n-1 && dp[i][j+1] != INT_MAX && dp[i][j] > dp[i][j+1]+1)//ÍùÓÒ
                        dp[i][j] = dp[i][j+1]+1;
                }
            }
        }
        
        return dp;
    }
};