class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        if(m < n || (m == 0&&n!=0))
            return -1;
        int idx = haystack.find(needle);
        if(idx == string::npos)
            return -1;
        return idx;
    }
};