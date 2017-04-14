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
    int ans = INT_MAX, val = -1;
public:
    int getMinimumDifference(TreeNode* root) {
        if(root->left)
            getMinimumDifference(root->left);
        if(val >= 0)
            ans = min(ans, root->val - val);
        val = root->val;
        if(root->right)
            getMinimumDifference(root->right);
        return ans;
    }
};