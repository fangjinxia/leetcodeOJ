class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        int n = nums.size();
        backTracking(nums, ans, 0);
        return ans;
    }
    
private:
    void backTracking(vector<int>& nums, vector<vector<int>>& ans, int srt){
        if(srt >= nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = srt; i < nums.size(); i++){
            swap(nums[srt], nums[i]);
            backTracking(nums, ans, srt+1);
            swap(nums[srt], nums[i]);
        }
    }
};