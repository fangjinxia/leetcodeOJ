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
    int sumNumbers(TreeNode* root) {
        int ans=0;
        ans = dfsWithRecursion(0, root);
        return ans;
    }
    
private:
    int dfsWithRecursion(int temp, TreeNode* root){
        if(root == NULL)
            return 0;
        temp = temp*10 + root->val;
        if(!root->left && !root->right){
            return temp;
        }
        return dfsWithRecursion(temp, root->left) + dfsWithRecursion(temp, root->right);
        
        
    }
};