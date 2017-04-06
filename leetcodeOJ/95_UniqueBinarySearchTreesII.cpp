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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if(n == 0)
            return ans;
        return genTree(1, n);
    }

private:
    vector<TreeNode*> genTree(int lo, int hi){
        vector<TreeNode*> ans;
        if(lo > hi){
            ans.push_back(NULL);   
            return ans;
        }
        if(lo == hi){
            TreeNode* root = new TreeNode(lo);
            ans.push_back(root);
            return ans;
        }
        
        for(int i = lo; i <= hi; i++){
            vector<TreeNode*> l = genTree(lo, i-1);
            vector<TreeNode*> r = genTree(i+1, hi);
            
            for(int j = 0; j < l.size(); j++){
                for(int k = 0; k < r.size(); k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = l[j];
                    root->right = r[k];
                    ans.push_back(root);
                }
            }
            
        }
        
        return ans;
    }
};