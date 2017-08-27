class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool hasModify = false;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] >= nums[i-1])
                continue;
            else{
                if(hasModify)
                    return false;
                else{
                    if(i == 1)
                        nums[i] = min(nums[i-1], nums[i]);
                    else{
                        if(nums[i] < nums[i-2])
                            nums[i] = max(nums[i], nums[i-1]);                            
                    }
                    hasModify = true;
                }
            }
        }
        
        return true;
    }
};