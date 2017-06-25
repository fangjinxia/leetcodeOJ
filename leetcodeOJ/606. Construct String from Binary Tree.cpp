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
    string tree2str(TreeNode* t) {
        string res = "";
        if(!t)
            return res;
            
        string left = tree2str(t->left);
        string right = tree2str(t->right);
        
        res = to_string(t->val);
        if(right.length())
            res += "(" + left + ")" + "(" + right + ")";
        else if(left.length())
            res += "(" + left + ")";
        return res;
     }
};