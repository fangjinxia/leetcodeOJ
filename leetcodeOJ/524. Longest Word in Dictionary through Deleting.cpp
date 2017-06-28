class Solution {
public:
    
    string findLongestWord(string s, vector<string>& d) {
        vector<string> res(0);
        for(int i = 0; i < d.size(); ++i){
            if(canBeFormed(d[i], s)){
                res.push_back(d[i]);
            }
        }
        
        if(res.size() == 0)
            return "";
        
        sort(res.begin(), res.end(), [](string a, string b){
            if(a.length() > b.length())
                return true;
            else if(a.length() == b.length()){
                int i = 0;
                while(i < a.length()){
                    if(a[i] < b[i])
                        return true;
                    else if(a[i] == b[i]){
                        ++i;
                        continue;
                    }
                    else
                        return false;
                }
            }
            return false;
        });
        
        return res[0];
    }
    
    
    bool canBeFormed(string str, string s){
        int i = str.length()-1;
        for(int j = s.length()-1; i >= 0 && j >= 0;){
            if(str[i] == s[j]){
                --i;
            }
            --j;
            
        }
        
        if(i < 0)
            return true;
        return false;
    }
};