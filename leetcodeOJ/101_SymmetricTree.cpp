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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isSymm(root->left, root->right);
    }
    
private:
    bool isSymm(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL)   
            return true;
        else if(left && right && (left->val == right->val)){
            return isSymm(left->left, right->right) && isSymm(left->right, right->left);
            
        }
        return false;
    }
};