class Solution {
public:
    string frequencySort(string s) {
        int dp[256] = {0};
        if(s.length() < 3)
            return s;
            
        for(int i = 0; i < s.length(); i++){
            dp[s[i]]++;
        }
        sort(s.begin(), s.end(), [&](char a, char b){
            return dp[a] > dp[b] || (dp[a] == dp[b] && a < b);
        });
        
        return s;
    }
};