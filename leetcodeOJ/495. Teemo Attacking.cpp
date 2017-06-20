class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        for(int i = 0; i < timeSeries.size(); ++i){
            if(i == timeSeries.size()-1|| (timeSeries[i+1] - timeSeries[i] >= duration))
                res += duration;
            else if(timeSeries[i+1] - timeSeries[i] < duration)
                res += timeSeries[i+1] - timeSeries[i];
        }
        
        return res;
    }
};