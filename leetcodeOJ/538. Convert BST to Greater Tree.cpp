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
    TreeNode* convertBST(TreeNode* root) {
        //先右子树，再根，再左子树
        helper(root);
        return root;
    }
    
    void helper(TreeNode* root){
        if(root == NULL)
            return;
        if(root->right)
            helper(root->right);
        sum += root->val;
        root->val = sum;
        if(root->left)
            helper(root->left);
    }

private:
    int sum = 0;
};