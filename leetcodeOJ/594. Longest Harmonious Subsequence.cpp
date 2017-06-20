class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        map<int, int> m;
        for(int i = 0; i < nums.size(); ++i){
            ++m[nums[i]];
        }
        
        int res = 0;
        int freq1 = 0;
        int num1 = 0;
        for(pair<int, int> p : m){
            int freq = 0;
            if(freq1 && p.first == num1+1){
                freq = freq1 + p.second;
            }
            res = max(res, freq);
            freq1 = p.second;
            num1 = p.first;
        }
        return res;
    }
};