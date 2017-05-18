class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        int n = abs(num);
        string s = (num >= 0) ? "" : "-";
        string str = "";
        while(n){
            str += to_string(n%7);
            n /= 7;
        }
        reverse(str.begin(), str.end());
        return s+str;   
    }
};