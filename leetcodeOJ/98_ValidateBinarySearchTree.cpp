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
    bool isValidBST(TreeNode* root) {
      //  cout << LONG_MIN << " "<< LONG_MAX;
        return isVal(root, LONG_MIN, LONG_MAX);
    }

private:
    bool isVal(TreeNode* root, long lo, long hi){
        if(!root)
            return true;
        
        int v = root->val;
        if(v >= hi || v <= lo)
            return false;
        return isVal(root->left, lo, v) && isVal(root->right, v, hi);
    }
};