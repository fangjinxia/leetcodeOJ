class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        if(n == 0){
            return ans;
        }
        unordered_map<string, multiset<string>> mp;
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].insert(strs[i]);
        }
        
        for(auto m : mp){
            vector<string> res(m.second.begin(), m.second.end());
            ans.push_back(res);
        }
        
        return ans;
    }
};