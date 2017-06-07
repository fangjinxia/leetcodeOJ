class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int k = 0; k < strs.size(); k++){
            //计算strs[k]中1的个数和0的个数
            int num1 = 0;
            int num0 = 0;
            for(int r = 0; r < strs[k].length(); r++){
                if(strs[k][r] == '0')
                    num0++;
                else
                    num1++;
            }
            
            for(int i = m; i >= num0; i--){
                for(int j = n; j >= num1; j--){
                    dp[i][j] = max(1+dp[i-num0][j-num1], dp[i][j]);
                }
            }
        }
        
        return dp[m][n];
    }
};