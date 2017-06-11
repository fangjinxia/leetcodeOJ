class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(0);
        ans.push_back(0);
        backTrace(ans, n, 1);
        return ans;
    }
    
    void backTrace(vector<int>& ans, int n, int adder){
        if((adder>>n) == 1)
            return;
        
        for(int i = ans.size()-1; i >= 0; --i){
            ans.push_back(adder + ans[i]);
        }
        backTrace(ans, n, adder*2);
    }
};