class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0)
            return false;
            
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = i-1; j >= 0; j--){
                if(dp[j]){
                    string w = s.substr(j, i-j);
                    vector<string>::const_iterator re = find(wordDict.begin(), wordDict.end(), w);
                    if(re != wordDict.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[n];
    }
};