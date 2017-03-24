class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        
        vector<int> temp;
        combination(candidates, target, ans, temp, 0);
        return ans;
    }
    
private:
    void combination(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &temp, int srt){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        //回溯
        for(int i = srt; i < candidates.size() && candidates[i] <= target; i++){
            temp.push_back(candidates[i]);
            combination(candidates, target-candidates[i], ans, temp, i);//因为集合中的数字可以无限次重复
            temp.pop_back();
        }
    }
};