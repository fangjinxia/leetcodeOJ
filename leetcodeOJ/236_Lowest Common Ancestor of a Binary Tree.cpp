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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == root || q == root)
            return root;
        TreeNode* lt = lowestCommonAncestor(root->left, p, q);
        TreeNode* rt = lowestCommonAncestor(root->right, p, q);
        //return (lt==NULL) ? rt : (rt==NULL) ? lt : root;
       if(lt != NULL && rt != NULL)
            return root;
        else if(lt != NULL && rt == NULL)
            return lt;
        else
            return rt;
    }
};