class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> v1(256, 0);
        vector<int> v2(256, 0);
        if(s.length() != t.length())
            return false;
        for(int i = 0; i < s.length(); i++){
            if(v1[s[i]] == 0){
                v1[s[i]] = t[i];
            }
            else{
                if(v1[s[i]] != t[i])
                    return false;
            }
            if(v2[t[i]] == 0){
                v2[t[i]] = s[i];
            }
            else{
                if(v2[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};