class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int maxLen = -1;
        for(int i = 0; i < strs.size(); ++i){
            int curLen = strs[i].length();
            bool flag = true;
            for(int j = 0; j < strs.size(); ++j){
                if(i != j && hasCommon(strs[i], strs[j])){
                    flag = false;
                    break;
                }
            }
            if(flag){
                maxLen = max(maxLen, curLen);
            }
        }
        return maxLen;
    }
    
    bool hasCommon(string a, string b){
        int re_a = a.length();
        int re_b = b.length();
        for(; re_a > 0 && re_b > 0; ){
            int i = a.length()-re_a;
            int j = b.length()-re_b;
            if(a[i] == b[j])
                re_a--;
            re_b--;
        }
        
        return re_a == 0;
    }
};