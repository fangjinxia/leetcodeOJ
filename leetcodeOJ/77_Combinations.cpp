class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        // if(k == 0 || n < k)
        //     return ans;
        vector<int> re;
        genCom(ans, re, 1, n, k);
        return ans;    
    }
    
private:
    void genCom(vector<vector<int>>& ans, vector<int>& re, int i, int n, int k){
        if(re.size() == k){
            ans.push_back(re);
            return;
        }
        if(i > n)
            return;
        re.push_back(i);
        genCom(ans, re, i+1, n, k);
        re.pop_back();
        genCom(ans, re, i+1, n, k);
    }
};