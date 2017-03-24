class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        backTracking(nums, ans, 0);
        return ans;
    }
    
private:
	//vector<int>& num程序出错，
	//需值传递，引用传递会改变值，
    void backTracking(vector<int> nums, vector<vector<int>>& ans, int srt){
        if(srt == nums.size()-1){
            ans.push_back(nums);
            return;
        }
        
        for(int i = srt; i < nums.size(); i++){
            if(i == srt || nums[i] != nums[srt]){
                swap(nums[srt], nums[i]);
                backTracking(nums, ans, srt+1);
            }
        }
    }
};