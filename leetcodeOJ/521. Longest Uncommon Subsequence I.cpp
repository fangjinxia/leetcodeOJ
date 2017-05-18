class Solution {
public:
    int findLUSlength(string a, string b) {
        int m = a.length();
        int n = b.length();
        if(m != n){
            return (m>n)?m:n;
        }
        if(a == b)
            return -1;
            
        return m;
    }
};