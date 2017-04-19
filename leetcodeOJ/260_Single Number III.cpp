class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                if(nums[i] != nums[i+1])
                    ans.push_back(nums[i]);
            }
            else if(i == nums.size()-1){
                if(nums[i] != nums[i-1])
                    ans.push_back(nums[i]);
            }
            else{
                if(nums[i] != nums[i-1] && nums[i] != nums[i+1])
                    ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};