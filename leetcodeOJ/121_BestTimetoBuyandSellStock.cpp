class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;//����û�н��ף���û���������Խ�����Ϊ0
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