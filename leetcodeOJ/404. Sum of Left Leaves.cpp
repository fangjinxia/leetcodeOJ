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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        
        genSum(root, &ans);
        return ans;
    }
    
    void genSum(TreeNode* root, int *ans){
        if(!root)
            return ;
        if(root && root->left && !root->left->left && !root->left->right){
            *ans += root->left->val;
            if(root->right)
                genSum(root->right, ans);
            return;
        }
        else{
            if(root->left)
                genSum(root->left, ans);
            if(root->right)
                genSum(root->right, ans);
        }
    }
};


//另一种方法
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (root->left && !root->left->left && !root->left->right) return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};