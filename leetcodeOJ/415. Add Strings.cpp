class Solution {
public:
    string addStrings(string num1, string num2) {
        string s = "";//目标串
        int c = 0;//进位
        for(int i = num1.length()-1, j = num2.length()-1; i >= 0 || j >= 0; i--, j--){
            int tmp1 = (i>=0) ? (num1[i]-'0') : 0;
            int tmp2 = (j>=0) ? (num2[j]-'0') : 0;
           // cout << tmp1 << ' ' << tmp2 << endl;
            s += to_string((tmp1+tmp2+c) % 10);
            c = (tmp1+tmp2+c) / 10;
        }
        if(c != 0){
            s += to_string(c);
        }
        
        reverse(s.begin(), s.end());
        return s;
    }
};