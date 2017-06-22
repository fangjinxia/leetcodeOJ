class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> re;
        vector<vector<string>> ans;
        
        backTrace(ans, re, s, 0);
        
        return ans;
    }
    
    void backTrace(vector<vector<string>>& ans, vector<string>& re, string s, int k){
        if(k == s.length()){
            ans.push_back(re);
            return ;
        }
        
        for(int i = k; i < s.length(); ++i){
            int lo = k;
            int hi = i;
            //s[lo-hi]ÊÇ»ØÎÄ´®
            while(lo < hi && s[lo] == s[hi]){
                ++lo;
                --hi;
            }
            if(lo >= hi){
                re.push_back(s.substr(k, i-k+1));
                backTrace(ans, re, s, i+1);
                re.pop_back();
            }
            
        }
    }
};