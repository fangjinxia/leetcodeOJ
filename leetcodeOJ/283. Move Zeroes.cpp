class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)
                continue;
            else{
                nums[idx++] = nums[i];
            }
        }
        //cout << idx;
        for(; idx < nums.size();){
            nums[idx++] = 0;
        }
        
    }
};