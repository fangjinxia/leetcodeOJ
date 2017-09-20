class Solution {
public:
    bool validPalindrome(string s) {
        int lo = -1; 
        int hi = s.length();
        while(++lo < --hi){
            if(s[lo] != s[hi]){
                return isValid(s, lo, hi-1) || isValid(s, lo+1, hi);
            }
        }
        return true;
    }
    
    bool isValid(string s, int lo, int hi){
        while(lo < hi){
            if(s[lo] != s[hi])
                return false;
            ++lo;
            --hi;
        }
        return true;
    }
};