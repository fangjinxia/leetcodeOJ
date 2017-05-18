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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans = calc(root->left)+calc(root->right);
        return max(ans, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
    
    int calc(TreeNode* root){
        if(!root)
            return 0;
        int ld = calc(root->left);
        int rd = calc(root->right);
        return 1+max(ld, rd);
    }
};