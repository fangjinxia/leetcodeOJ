class Solution {
public:
    int lengthOfLastWord(string s) {
        if(!s.size())
            return 0;
        // cout << s.size();
        int ans = 0;
        int i = s.size()-1;
        while(i>=0 && s[i]== ' '){
            i--;
        }
        for(; i>=0 && s[i] != ' '; i--){
            ans++;
        }
        
        return ans;
    }
};