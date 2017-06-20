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
    int countNodes(TreeNode* root) {
        int res = 0;
        if(!root)
            return res;
        
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh == rh)
            return (1 << lh) + countNodes(root->right);
        else
            return (1 << rh) + countNodes(root->left);
    }
    
    int height(TreeNode* root){
        if(!root)
            return 0;
        return 1+height(root->left);
    }
};