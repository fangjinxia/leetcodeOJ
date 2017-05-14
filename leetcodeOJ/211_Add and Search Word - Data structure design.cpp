class WordDictionary {
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
    
    WordDictionary() {
        root = new TreeNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TreeNode *cur = root;
        for(int i = 0; i < word.length(); i++){
            int idx = word[i] - 'a';
            if(cur->next[idx] == NULL)
                cur->next[idx] = new TreeNode();
            cur = cur->next[idx];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return query(word, root);
    }
    
private:
    TreeNode* root;
    
    bool query(string word, TreeNode* node){
        TreeNode *cur = node;
        for(int i = 0; word[i]; i++){
            if(cur && word[i] == '.'){
                TreeNode *tmp = cur;
                for(int j = 0; j < 26; j++){
                    cur = tmp->next[j];
                    if(query(word.substr(i+1), cur))
                        return true;
                    
                }
            }
            else if(cur && word[i] != '.'){
                int idx = word[i]-'a';
                cur = cur->next[idx];
            }
            else
                break;
        }
        return cur && cur->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */