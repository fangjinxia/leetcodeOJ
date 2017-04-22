class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        for(int lo = 0; lo < nums.size()-1;){
            while(lo < nums.size()-1 && nums[lo] >= nums[lo+1])
                lo++;
            int hi = lo+1;
            while(hi < nums.size()-1 && nums[hi] <= nums[hi+1])
                hi++;
            int mid = hi+1;
            while(mid < nums.size()){
                if(nums[mid] < nums[hi] && nums[mid] > nums[lo])
                    return true;
                mid++;
            }
            lo = hi+1;
        }
        
        return false;
    }
};