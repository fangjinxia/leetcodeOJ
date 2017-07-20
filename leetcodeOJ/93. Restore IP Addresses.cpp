class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.length() == 0)
            return ans;
        string re = "";
        genIPAddr(ans, re, s, 0, 0);
        return ans;
    }
private:
    void genIPAddr(vector<string>& ans, string re, string s, int idx, int cnt){
        if(cnt > 4){
            return;
        }
        
        if(cnt == 4 && idx == s.length()){
            ans.push_back(re);
            return;
        }
        
        for(int i = 1; i < 4; ++i){
            if(idx+i > s.length())
                break;
            string str = s.substr(idx, i);
            if((str[0] == '0' && i > 1) || (i == 3 && str > "255")){
                continue;
            }
            
            genIPAddr(ans, re + str + ((cnt == 3) ? "" : "."), s, idx+i, cnt+1);
        }
    }
    
};