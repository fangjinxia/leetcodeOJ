class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        if(n > s2.length())
            return false;
        vector<int> v1(26, 0);
        for(int i = 0; i < n; i++){
            v1[s1[i] - 'a']++;
        }
        
        vector<int> v2(26, 0);
        for(int i = 0; i < s2.length(); i++){
            v2[s2[i] - 'a']++;
            if(i >= n)
                v2[s2[i-n] - 'a']--;
            
            if(v1 == v2)
                return true;
        }
        
        return false;
    }
};