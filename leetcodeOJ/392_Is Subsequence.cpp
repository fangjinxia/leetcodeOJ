class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() > t.length())
            return false;
        if(s.length() == 0)
            return true;
            
        int idxs = 0;
        int idxt = 0;
        for(; idxs < s.length() && idxt < t.length(); ){
            if(s[idxs] == t[idxt])
                idxs++;
            idxt++;
        }
        if(idxs == s.length())
            return true;
        else
            return false;
        
    }
};