class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //»ØËÝ
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        
        vector<int> temp;
        combination(candidates, ans, target, temp, 0);
        return ans;
    }
    
private:
    void combination(vector<int>& candidates, vector<vector<int>>& ans, int target, vector<int>& temp, int srt){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        for(int i = srt; i < candidates.size() && candidates[i] <= target; i++){
            if(i == srt || candidates[i] != candidates[i-1]){
                temp.push_back(candidates[i]);
                combination(candidates, ans, target-candidates[i], temp, i+1);
                temp.pop_back();
            }
        }
    }
};