class Solution {
public:
    string toHex(int num) {
        if(num == 0)
            return "0";
        long long M = 4294967296;
        long long n = (num < 0) ? (M+num) : (long long)(num);
        
        string v = "0123456789abcdef";
        string s = "";
        while(n){
            s += v[n%16];
            n /= 16;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};