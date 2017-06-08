class Solution {
public:
    //求最长不连续公共子串的长度
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int re = 0;
        int dp[len1+1][len2+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                re = max(re, dp[i][j]);
            }
        }
        cout << re<< endl;
        return len1+len2-2*re;
    }
};