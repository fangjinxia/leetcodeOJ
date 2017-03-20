class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        ///<思路：因为时间复杂度为logn，且数组有序，那么可以采用二分法
        int left = 0;
        int right = nums.size()-1;
        
        int mid = 0;
        vector<int> ans(2, -1);
        
        while(left <= right){
            mid = left + (right-left)/2;
            if(nums[mid] > target)
                right = mid-1;
            else if(nums[mid] < target)
                left = mid+1;
            else if(nums[mid] == target){
                int k = mid-1;
                while(nums[k] == target && k >= 0){ ///<注意边界
                    k--;
                }
                ans[0] = k+1;
                k = mid+1;
                while(nums[k] == target && k <= (nums.size()-1)){///<注意边界
                    k++;
                }
                ans[1] = k-1;
                
                return ans;
            }
        }
        
        return ans;
    }
};