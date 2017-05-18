/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> m;
        genAns(root, m);
        int cnt = 0;
        unordered_map<int, int>::iterator it;
        for(it = m.begin(); it != m.end(); it++){
            cnt = max(cnt, it->second);
        }
        vector<int> ans;
        for(it = m.begin(); it != m.end(); it++){
            if(it->second == cnt){
                ans.push_back(it->first);
            }
        }
        
        return ans;
    }
    
    void genAns(TreeNode* root, unordered_map<int, int>& m){
        if(!root)
            return ;
        
        unordered_map<int, int>::iterator it = m.find(root->val);
        if(it != m.end()){
            it->second += 1;
        }
        else{
            m.insert(unordered_map<int, int>::value_type(root->val, 1));
        }
        genAns(root->left, m);
        genAns(root->right, m);
        
    }
};