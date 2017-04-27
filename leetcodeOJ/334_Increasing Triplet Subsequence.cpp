class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)   
            return false;
        for(int i = 1; i < n-1; i++){
            if(nums[i-1] < nums[i]){
                int idx1 = i-1, idx2 = i;
                int tmp = i;
                while(i < n-1){
                    i++;
                    if(nums[i] > nums[idx2])
                        return true;
                    else if(nums[i] < nums[idx2] && nums[i] > nums[idx1])
                        idx2 = i;
                }
                i = tmp;
            }
            
        }
        return false;
    }
};