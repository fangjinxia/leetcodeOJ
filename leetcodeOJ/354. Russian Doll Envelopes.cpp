class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if(n <= 1)
            return n;
            
        vector<int> dp(n, 0);
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int>& a, pair<int, int>& b){
            return (a.first < b.first) || ((a.first == b.first) && (a.second < b.second));
        });
        
        dp[0] = 1;
        for(int i = 1; i < n; ++i){
            dp[i] = 1;
            for(int j = 0; j < i; ++j){
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            //cout << dp[i] << endl;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};