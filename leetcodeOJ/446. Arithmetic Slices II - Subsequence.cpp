class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() <= 2)
            return 0;
        
        vector<unordered_map<int, int>> dp(A.size());//[index, [difference, count]]
        int ans = 0;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < i; j++){
                if((long long)A[i] - (long long)A[j] > INT_MAX || (long long)A[i] - (long long)A[j] < INT_MIN)
                    continue;
                int diff = A[i]-A[j];
                dp[i][diff] += 1;
                if(dp[j].find(diff) != dp[j].end()){
                    dp[i][diff] += dp[j][diff];
                    ans += dp[j][diff];
                }
                
            }
        }
        return ans;
    }
};