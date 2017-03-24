class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if(len < 4)
            return ans;
        for(int i = 0; i < len - 3; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
                    break;
            if(nums[i] + nums[len-3] + nums[len-2] + nums[len-1] < target)
                    continue;
                    
            for(int j = i + 1; j < len -2; j++){
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target)
                    break;
                if(nums[i] + nums[j] + nums[len-2] + nums[len-1] < target)
                    continue;
                    
                int left = j+1;
                int right = len-1;
                while(left<right){
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum < target)
                        left++;
                    else if(sum > target)
                        right--;
                    else{
                        vector<int> res = {nums[i], nums[j], nums[left], nums[right]};
                        ans.push_back(res);
                        do{
                            left++;
                        }while(nums[left] == nums[left-1] && left < right);
                        do{
                            right--;
                        }while(nums[right] == nums[right+1] && left < right);
                    }
                }
                
            }
        }
        
        return ans;
    }
};