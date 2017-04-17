class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string str[3] = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        vector<string> s(str, str+3);
        vector<string> ans;
        for(int i = 0; i < words.size(); i++){
            int idx = 0;
            for(; idx < 3; idx++){
                if(s[idx].find(words[i][0]) != string::npos)
                    break;
            }
            //cout << idx << endl;
            int j = 1;
            for(; j < words[i].size(); j++){
                if(s[idx].find(words[i][j]) == string::npos)
                    break;
            }
            if(j == words[i].size())
                ans.push_back(words[i]);
        }
        return ans;
    }
};