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
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        return sumUp(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum); 
    }
    
    int sumUp(TreeNode* root, int sum){
        if(!root)
            return 0;
        return (sum == root->val) + sumUp(root->left, sum-root->val) + sumUp(root->right, sum-root->val);
    }
};