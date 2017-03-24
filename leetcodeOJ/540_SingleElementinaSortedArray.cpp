class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //二分法
        int left = 0;
        int right = nums.size()-1;
        while(left < right){
            int mid = left + (right-left)/2;
            //mid是偶数
            if(mid % 2 == 0){
                if(nums[mid] == nums[mid-1])
                    right = mid - 2;
                else if(nums[mid] == nums[mid+1])
                    left = mid + 2;
                else 
                    return nums[mid];
            }
            else{
                if(nums[mid] == nums[mid-1])
                    left = mid + 1;
                else if(nums[mid] == nums[mid+1])
                    right = mid - 1;
            } 
        }
        
        return nums[left];
    }
};