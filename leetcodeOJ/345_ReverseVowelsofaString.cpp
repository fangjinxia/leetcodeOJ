class Solution {
public:
    string reverseVowels(string s) {
        int lo = 0; 
        int hi = s.length()-1;
        string str = "aeiouAEIOU";
        while(lo < hi){
            lo = s.find_first_of(str, lo);
            hi = s.find_last_of(str, hi);
            if(lo < hi)
                swap(s[lo], s[hi]);
            lo++;
            hi--;
        }
        
        return s;
    }
};