class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.length(); ++i){
            for(int j = i; j < s.length(); ++j){
                string ss = s.substr(i, j-i+1);
                if(isPalinSubstr(ss)){
                    ++ans;
                }
            }
        }
        return ans;
    }
    
    bool isPalinSubstr(string ss){
        int hi = ss.length() - 1;
        int lo = 0;
        
        while(lo <= hi){
            if(ss[lo++] != ss[hi--])
                return false;
        }
        
        return true;
    }
};