class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        unordered_map<string, int>::iterator it;
        vector<string> ans;
        if(s.length() <= 10)
            return ans;
            
        for(int i = 0; i <= s.length()-10; ++i){
            string str = s.substr(i, 10);
            it = m.find(str);
            if(it != m.end()){
                if(it->second == 1)
                    ans.push_back(str);
                it->second += 1;
                    
            }
            else{
                m[str] = 1;
            }
        }
        return ans;
    }
};