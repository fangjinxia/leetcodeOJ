class Solution {
public:
    void reverseWords(string &s) {
        int n = s.length();
        string ans = "";
        string str = "";
        for(int i = 0; i < n; i++){
            if(s[i] != ' '){
                str += s[i];
            }
            else{
                if(str.length() == 0)
                    continue;
                reverse(str.begin(), str.end());
                if(ans.length() != 0)
                    ans += " ";
                ans += str;
                str = "";
            }
        }
        if(str.length() != 0){
            reverse(str.begin(), str.end());
            if(ans.length() != 0)
                ans += " ";
            ans += str;
        }
        
        reverse(ans.begin(), ans.end());
        s = ans;
    }
};