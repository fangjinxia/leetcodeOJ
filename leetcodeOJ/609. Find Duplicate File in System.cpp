class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        for(int i = 0; i < paths.size(); ++i){
            istringstream ss(paths[i]);
            vector<string> toks{ istream_iterator<string>{ss}, istream_iterator<string>{} };
            
            string path = toks[0];
            for(int j = 1; j < toks.size(); ++j){
                int pos = toks[j].find('(');
                string filename = toks[j].substr(0, pos);
                string content = toks[j].substr(pos+1, toks[j].size()-pos-2);
                m[content].push_back(path + "/" + filename);
            }
            
        }
        
        vector<vector<string>> res;
        for(auto x : m){
            if(x.second.size() > 1)
                res.push_back(x.second);
        }
        
        return res;
    }
};