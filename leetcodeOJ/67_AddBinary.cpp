class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() == 0)
            return b;
        if(b.length() == 0)
            return a;
            
        int n1 = a.length();
        int n2 = b.length();
        int c = 0;//½øÎ»
        int i = n1-1;
        int j = n2-1;
        string ans = "";
        for(; i >= 0 || j >= 0; i--, j--){
            int temp = ((i < 0)? 0 : (a[i] - '0')) + ((j < 0)? 0 : (b[j] - '0')) + c;
            c = temp / 2;
            ans += to_string(temp % 2);
        }
        if(c == 1)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};