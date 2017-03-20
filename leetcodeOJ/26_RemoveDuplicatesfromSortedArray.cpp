class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dup = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1])
                dup++;
            else
                nums[i-dup] = nums[i];
        }
        int ans = nums.size() - dup;
        return ans;
    }
};