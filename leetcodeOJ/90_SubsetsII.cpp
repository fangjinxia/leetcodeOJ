class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n == 0)
            return ans;
        vector<int> re;
        sort(nums.begin(), nums.end());
        genSet(ans, nums, re, n, 0);
        return ans;
    }
    
private:
    void genSet(vector<vector<int>>& ans, vector<int>& nums, vector<int>& re, int n, int m){
        ans.push_back(re);
        
        for(int i = m; i < n; ++i){
            if(i == m || nums[i] != nums[i-1]){
                re.push_back(nums[i]);
                genSet(ans, nums, re, n, i+1);
                re.pop_back();
            }
        }
    }
};