class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;//大不了没有交易，则没有利润，所以结果最低为0
        if(prices.size() == 0)
            return ans;
        int curLow = prices[0];
        for(int i = 1; i < prices.size(); i++){
            ans = max(ans, prices[i]-curLow);
            curLow = min(curLow, prices[i]);
        }
        return ans;
    }
};