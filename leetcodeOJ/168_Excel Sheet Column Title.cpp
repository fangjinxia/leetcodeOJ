class Solution {
public:
    string convertToTitle(int n) {
        //十进制转26进制
        string s = "";
        while(n != 0){
            n--;
            s = char('A' + n%26)+ s;
            n /= 26;
        }
        return s;
    }
};