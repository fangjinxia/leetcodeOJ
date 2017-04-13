class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 0)
            return ans;
        genPar(ans, "", n, 0);
        return ans;
    }
    
private:
    void genPar(vector<string>& ans, string s, int n, int m){
        if(m == 0 && n == 0){
            ans.push_back(s);
            return;
        }
        if(m != 0){
            genPar(ans, s+')', n, m-1);
        }
        if(n != 0){
            genPar(ans, s+'(', n-1, m+1);
        }
    }
};