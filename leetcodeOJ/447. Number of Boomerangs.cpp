class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        vector<vector<int>> dp(points.size(), vector<int>(points.size(), 0));
        for(int i = 0; i < points.size()-1; i++){
            for(int j = i+1; j < points.size(); j++){
                dp[i][j] = (points[i].first - points[j].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) *  (points[i].second - points[j].second);
                dp[j][i] = dp[i][j];
                // cout << dp[i][j]<< endl;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < dp.size(); i++){
            sort(dp[i].begin(), dp[i].end());
            int tmp = 1;
            for(int j = 1; j < dp[i].size(); j++){
                if(dp[i][j] == dp[i][j-1])
                    tmp++;
                else{
                    ans += (tmp*(tmp-1));
                    tmp = 1;
                }
            }
            ans += (tmp*(tmp-1));
            // cout << tmp<< endl;
        }
    
        return ans;
    }
    
};