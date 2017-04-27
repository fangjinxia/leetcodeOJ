class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size() == 0)
            return nums;
            
        vector<int> ans(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            if(i == nums.size()-1)
                ans[i] = 0;
            else{
                int k = 0;
                for(int j = i+1; j < nums.size(); j++){
                    if(nums[j] < nums[i])
                        k++;
                }
                ans[i] = k;
            }
        }
        return ans;
    }
};