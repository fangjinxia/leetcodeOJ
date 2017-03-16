
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int left = i+1;
            int right = nums.size()-1;
            int target = 0-nums[i];

            while(left < right){
                if((nums[left] + nums[right]) < target){
                    left++;
                }
                else if((nums[left] + nums[right]) > target){
                    right--;
                }
                else{
                    vector<int> res;
                    res.push_back(nums[i]);
                    res.push_back(nums[left]);
                    res.push_back(nums[right]);
                    ans.push_back(res);

                    while(left < right && nums[left] == nums[left+1]){
                        left++;
                    }
                    left++;
                    while(left < right && nums[right] == nums[right-1]){
                        right--;
                    }
                    right--;
                }
            }
        }

        return ans;
    }
};
