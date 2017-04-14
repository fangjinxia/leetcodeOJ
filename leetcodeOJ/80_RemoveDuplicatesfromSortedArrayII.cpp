class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return n;
        vector<int> newArr(n);
        int len = 2;
        newArr[0] = nums[0];
        newArr[1] = nums[1];
        for(int i = 2; i < n; i++){
            if(nums[i] == nums[i-1] && nums[i] == nums[i-2]){
                continue;
            }
            else
                newArr[len++] = nums[i];
        }
        swap(newArr, nums);
        return len;
    }
};