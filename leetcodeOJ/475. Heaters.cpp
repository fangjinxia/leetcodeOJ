class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if(heaters.size() == 0)
            return 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int radius = 0;
        int idx = 0;
        for(int i = 0; i < houses.size(); i++){
            while(idx < heaters.size()-1 && (abs(heaters[idx+1] - houses[i]) <= abs(heaters[idx] - houses[i]))){
                idx++;
            }
            radius = max(radius, abs(heaters[idx] - houses[i]));
        }
        return radius;
    }
};