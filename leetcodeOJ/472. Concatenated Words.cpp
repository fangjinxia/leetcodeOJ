class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        vector<string> res;
        for(string word : words){
            int n = word.length();
            vector<int> dp(n+1);
            dp[0] = 1;
            for(int i = 0; i < n; ++i){
                if(dp[i] == 0)
                    continue;
                //i = 0, j = n 的情况需要排除，
                for(int j = i+1; j <= n; ++j){
                    if(j-i < n && s.count(word.substr(i, j-i)))
                        dp[j] = 1;
                }
                if(dp[n]){
                    res.push_back(word);
                    break;
                }
            }
        }
        
        return res;
    }
};