class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<int> ans;
        if(m < n)
            return ans;
        for(int i = 0; i <= m-n; i++){
            string ss = s.substr(i, n);
            if(isValidAna(ss, p))
                ans.push_back(i);
        }
        return ans;
    }

private:
    bool isValidAna(string s, string t){
        vector<int> v(26, 0);
        for(int i = 0; i < s.length(); i++){
            v[s[i] - 'a']++;
            v[t[i] - 'a']--;
        }
        for(auto num : v){
            if(num > 0)
                return false;
        }
        return true;
    }
    
};