class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        if(prices.size() < 2)
            return 0;
        ///<˼·���������У�profitΪ���ֵ����Сֵ�Ĳ�ֵ
        for(int i = 0; i < prices.size()-1; i++){
            if(prices[i] < prices[i+1]){
                int min = prices[i];//buy
                i++;
                while((i < prices.size()-1) && prices[i] < prices[i+1]){
                    i++;
                }
                int max = prices[i];//sell
                ans += max-min;
            }
        }
        return ans;
    }
};