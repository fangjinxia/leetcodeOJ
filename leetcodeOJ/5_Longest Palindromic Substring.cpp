class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n < 2)
            return s;
        
        for(int i = 0; i < n-1; i++){
            genAns(s, i, i);
            genAns(s, i, i+1);
        }
        
        return s.substr(low, maxLen);
    }
private:
    int low = 0, maxLen = 1;
    void genAns(string s, int lo, int hi){
        while(lo >= 0 && hi < s.length() && s[lo] == s[hi]){
            hi++;
            lo--;
        }
        if(maxLen < hi-lo-1){
            low = lo+1;
            maxLen = hi-lo-1;
        }
    }
};