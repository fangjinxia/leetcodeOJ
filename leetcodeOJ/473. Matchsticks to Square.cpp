class Solution {
public:
    bool makesquare(vector<int>& nums) {
        long sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 4 && nums.size() < 4)
            return false;
            
        long sideLen = sum / 4;
        vector<int> usedMasks;
        vector<bool> validHalfSubsets(1<<nums.size(), false);
        
        int all = (1<<nums.size())-1;
        for(int mask = 0; mask <= all; ++mask){
            long subsetSum = 0;
            for(int i = 0; i < 32; ++i){
                if((mask>>i) & 1)
                    subsetSum += nums[i];
            }
            
            if(subsetSum == sideLen){
                for(int usedMask : usedMasks){
                    if((usedMask & mask) == 0){
                        int validHalf = usedMask | mask;
                        validHalfSubsets[validHalf] = true;
                        if(validHalfSubsets[all ^ validHalf])
                            return true;
                    }
                }
                
                usedMasks.push_back(mask);
            }
            
        }
        return false;
    }
};