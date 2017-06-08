class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> re;
        backTrace(nums, ans, re, 0, 0);
        
       // for_each(ans.begin(), ans.end(), back_inserter(res));
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    
    void backTrace(vector<int>& nums, set<vector<int> >& ans, vector<int>& re, int size, int idx){
        if(size >= 2)
            ans.insert(re);
        
        for(int i = idx; i < nums.size(); ++i){
            if(re.size() == 0 || nums[i] >= re[re.size()-1]){
                re.push_back(nums[i]);
                backTrace(nums, ans, re, size+1, i+1);
                re.pop_back();
            }
        }
    }
};