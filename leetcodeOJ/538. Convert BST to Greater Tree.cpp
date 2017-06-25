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
        //�����������ٸ�����������
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