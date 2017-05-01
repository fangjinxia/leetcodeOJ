class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        if(n == 2 && nums[0] == nums[1]){
            ans.push_back(nums[0]);
            return ans;
        }
        else if(n < 3)
            return nums;
        
        int num = n/3+1;
        
        for(int i = 1; i < n; i++){
            int k = 1;
            while(i < n && nums[i] == nums[i-1]){
                i++;
                k++;
            }
            if(num <= k)
                ans.push_back(nums[i-1]);
        }
        return ans;
    }
};