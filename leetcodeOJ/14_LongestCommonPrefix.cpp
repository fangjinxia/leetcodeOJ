class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if(!strs.size())
            return prefix;
        for(int idx = 0; idx < strs[0].size(); idx++){
            for(int j = 1; j < strs.size(); j++){
                if(idx > strs[j].size() || strs[j][idx] != strs[j-1][idx]){
                    return prefix;
                }
            }
            prefix += strs[0][idx];
        }
        return prefix;
    }
};
