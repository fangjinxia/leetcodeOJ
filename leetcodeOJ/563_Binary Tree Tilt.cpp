/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 ///<ºóÐò±éÀú
class Solution {
public:
    int findTilt(TreeNode* root) {
        int ans = 0;
        genTilt(root, ans);
        return ans;
    }
    
private:
    int genTilt(TreeNode* root, int &ans){
        if(root == NULL)
            return 0;
        
        int l = genTilt(root->left, ans);
        int r = genTilt(root->right, ans);
        ans += abs(l - r);
        return l+r+root->val;
    }
};