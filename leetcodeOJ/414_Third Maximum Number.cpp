class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size() < 3)
            return *max_element(nums.begin(), nums.end());
            
        sort(nums.begin(), nums.end());
        vector<int> res(0);
        int n = nums.size();
        res.push_back(nums[n-1]);
        for(int i = nums.size()-2; i >= 0; i--){
            if(nums[i] == nums[i+1])
                continue;
            else
                res.push_back(nums[i]);
        }
        return (res.size() < 3) ? res[0] : res[2];
    }
};