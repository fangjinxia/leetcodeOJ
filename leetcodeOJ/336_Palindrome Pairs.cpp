class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> dict;
        
        for(int i = 0; i < words.size(); i++){
            string ss = words[i];
            reverse(ss.begin(), ss.end());
            dict[ss] = i;
        }
        
        if(dict.find("") != dict.end()){
            for(int i = 0; i < words.size(); i++){
                if(i == dict[""])
                    continue;
                if(isPal(words[i]))
                    ans.push_back({dict[""], i});
            }
        }
        
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].length(); j++){
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, words[i].size()-j);
                
                if(dict.find(left) != dict.end() && isPal(right) && dict[left] != i){
                    ans.push_back({i, dict[left]});
                }
                if(dict.find(right) != dict.end() && isPal(left) && dict[right] != i){
                    ans.push_back({dict[right], i});
                }
            }
        }
        
        return ans;
    }
    
    bool isPal(string word){
        int lo = 0;
        int hi = word.length()-1;
        while(lo < hi){
            if(word[lo++] != word[hi--])
                return false;
        }
        return true;
    }
};