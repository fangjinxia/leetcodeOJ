class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        // if(k < 1 || n < 1)
        //     return ans;
        vector<int> re;
        genComSum3(ans, re, 1, 9, k, n);
        return ans;
    }
    
private:
    void genComSum3(vector<vector<int>>& ans, vector<int>& re, int start, int end, int k, int n){
        if(n == 0 && k == 0){
            ans.push_back(re);
            return;
        }
        if(n < 0 || start > end)
            return;
        re.push_back(start);
        genComSum3(ans, re, start+1, end, k-1, n-start);
        re.pop_back();
        genComSum3(ans, re, start+1, end, k, n);
    }
};