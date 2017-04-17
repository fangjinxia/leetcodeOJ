class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums.push_back(nums[i]);
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int j = i+1;
            for(; j < 2*n; j++){
                if(nums[i] < nums[j]){
                    ans.push_back(nums[j]);
                    break;
                }
            }
            if(j == 2*n)
                ans.push_back(-1);
        }
        
        return ans;
    }
};