class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = nums[n-1] * nums[n-2] * nums[n-3];
        if(nums[0] * nums[n-1] >= 0)
            return res;
        else {
            int tmp = nums[0] * nums[1] * nums[n-1];
            return max(res, tmp);
        }
            
    }
};