class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2)
            return 0;
        
        int has1_doNothing = -prices[0];
        int has1_sell = 0;
        int has0_doNothing = 0;
        int has0_buy = -prices[0];
        
        for(int i = 1; i < n; ++i){
            has1_doNothing = (has1_doNothing > has0_buy) ? has1_doNothing : has0_buy;
            has0_buy = has0_doNothing - prices[i];
            has0_doNothing = (has0_doNothing > has1_sell) ? has0_doNothing : has1_sell;
            has1_sell = has1_doNothing + prices[i];
        }
        
        return (has1_sell > has0_doNothing) ? has1_sell : has0_doNothing;
    }
};