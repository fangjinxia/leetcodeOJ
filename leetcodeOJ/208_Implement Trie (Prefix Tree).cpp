class Trie {
public:
    /** Initialize your data structure here. */
    class TreeNode{
        public:
            TreeNode* next[26];
            bool isWord = false;
            TreeNode(){
                for(int i = 0; i < 26; i++){
                    next[i] = NULL;
                }  
            };
    };
    
    Trie() {
        root = new TreeNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode *cur = root;
        for(int i = 0; i < word.length(); i++){
            int idx = word[i] - 'a';
            if(cur->next[idx] == NULL)
                cur->next[idx] = new TreeNode();
            cur = cur->next[idx];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode *cur = root;
        for(int i = 0; i < word.length(); i++){
            int idx = word[i] - 'a';
            if(cur->next[idx] == NULL)
                return false;
            cur = cur->next[idx];
        }
        if(cur->isWord)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode *cur = root;
        for(int i = 0; i < prefix.length(); i++){
            int idx = prefix[i] - 'a';
            if(cur->next[idx] == NULL)
                return false;
            cur = cur->next[idx];
        }
        return true;
    }
    
private:
    TreeNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */