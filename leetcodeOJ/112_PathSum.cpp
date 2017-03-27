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
    bool hasPathSum(TreeNode* root, int sum) {
        return dfsWithRecursion(root, sum, 0);
    }
    
private:
    bool dfsWithRecursion(TreeNode* root, int sum, int temp){
        if(root == NULL)
            return false;
        temp += root->val;
        if(!root->left && !root->right)
            return sum==temp;
        return dfsWithRecursion(root->left, sum, temp) || dfsWithRecursion(root->right, sum, temp);
    }
};