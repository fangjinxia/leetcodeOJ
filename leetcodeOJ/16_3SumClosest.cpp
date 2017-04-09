class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return INT_MAX;
        
        int ans = 0;
        sort(nums.begin(), nums.end());
        int diff = abs(nums[0] + nums[1] + nums[2] - target);
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            int left = i+1;
            int right = nums.size()-1;
            
            while(left < right){
                int temp = nums[i] + nums[left] + nums[right];
                if(abs(target - temp) <= diff){
                    diff = abs(target - temp);
                    ans = temp;
                   // cout << ans << " " << diff << endl;
                }
                if(temp > target){
                    right--;
                    while(left < right && nums[right] == nums[right+1]){
                        right--;
                    }
                }
                else if(temp < target){
                    left++;
                    while(left < right && nums[left] == nums[left-1]){
                        left++;
                    }
                }
                else if(temp == target){
                    return target;
                }
                
                
            }
            
        }
        
        return ans;
    }
};