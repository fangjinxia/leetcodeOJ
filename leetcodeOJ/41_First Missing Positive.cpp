class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int k = -1;
        int i = 0;
        for(; i < nums.size(); i++){
            if(nums[i] == 1){
                k = i;
                break;
            }
        }
        if(k == -1)
            return 1;
        else{
            for(i = k+1; i < nums.size(); i++){
                if(nums[i] == nums[i-1])
                    continue;
                else if(nums[i] == nums[i-1] + 1)
                    continue;
                else
                    return nums[i-1]+1;
            }
        }
        return nums[i-1] + 1;
    }
};