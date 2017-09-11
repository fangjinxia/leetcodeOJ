class MagicDictionary {
public:
    unordered_set<string> mp;
    
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto item : dict){
            mp.insert(item);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(int i = 0; i < word.length(); ++i){
            char tmp = word[i];
            for(char c = 'a'; c <= 'z'; ++c){
                if(tmp == c)
                    continue;
                word[i] = c;
                if(mp.find(word) != mp.end())
                    return true;
                
            }
            word[i] = tmp;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */