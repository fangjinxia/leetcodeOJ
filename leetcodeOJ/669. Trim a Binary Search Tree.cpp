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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root)
            return NULL;
        
        if(root->val < L)
            return trimBST(root->right, L, R);
        else if(root->val > R)
            return trimBST(root->left, L, R);
        else{
            TreeNode* tmp = root;
            tmp->left = trimBST(root->left, L, R);
            tmp->right = trimBST(root->right, L, R);
            return tmp;
        }
    }
};