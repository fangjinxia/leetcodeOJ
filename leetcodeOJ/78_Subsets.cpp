class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n == 0)
            return ans;
        vector<int> re;
        genSet(ans, nums, re, n, 0);
        return ans;
    }
    
private:
    void genSet(vector<vector<int>>& ans, vector<int>& nums, vector<int>& re, int n, int m){
        if(n == m){
            ans.push_back(re);
            return;
        }
        re.push_back(nums[m]);
        genSet(ans, nums, re, n, m+1);
        re.pop_back();
        genSet(ans, nums, re, n, m+1);
    }
};