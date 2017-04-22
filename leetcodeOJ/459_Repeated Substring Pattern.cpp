class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int len = 1; len <= n>>1; len++){
            string str = s.substr(0, len);
            if(isRepeated(s, str))
                return true;
        }
        return false;
    }
    
private:
    bool isRepeated(string s, string str){
        int m = s.length();
        int n = str.length();
        if(m % n != 0)
            return false;
        
        int k = m / n;
        string ss = str;
        for(int i = 1; i < k; i++)
            ss += str;
            
        if(ss == s)
            return true;
        return false;
    }
};