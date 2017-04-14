class Solution {
public:
    string reverseStr(string s, int k) {
        if(k >= s.length()){
            reverse(s.begin(), s.end());
            return s;
        }
        int n = s.length();
        int pos1 = 0;
        string ans = "";
        int flag = 1;
        while(pos1 < n){
            if(flag == 0){
                if(pos1+k > n)
                    ans += s.substr(pos1);
                else
                    ans += s.substr(pos1, k);
                flag = 1;
            }
            else if(flag == 1){
                string str = s.substr(pos1, k);
                reverse(str.begin(), str.end());
                ans += str;
                flag = 0;
            }
            pos1 += k;
        }
        return ans;
    }
};