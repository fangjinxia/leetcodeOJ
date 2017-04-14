class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int pos = 0;
        int idx = 0;
        while((idx = s.find(' ', pos)) != string::npos){
            string str = s.substr(pos, idx-pos);
            reverse(str.begin(), str.end());
            ans += str;
            ans += ' ';
            pos = idx+1;
        }
        string str = s.substr(pos);
        reverse(str.begin(), str.end());
        ans += str;
        return ans;
    }
};