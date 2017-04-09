class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if(n == 0)
            return ans;
        
        for(int i = 0; i < n; i++){
            int start = nums[i];
            while(i+1 < n && (nums[i] + 1 == nums[i+1])){
                i++;
            }
            if(start != nums[i])
                ans.push_back(to_string(start) + "->" + to_string(nums[i])); 
            else if(i == n-1 || (start == nums[i])){
                ans.push_back(to_string(start));
            }  
        }
        
        return ans;
    }
};