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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!t && !s)
            return true;
        bool tmp = false;
        if(t && s){
            if(t->val == s->val){
                tmp = isSametree(s, t);
            }
            if(tmp)
                return true;
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
        return false;
    }
    
    bool isSametree(TreeNode* s, TreeNode* t){
        if(!t && !s)
            return true;
        if(s && t)
            return s->val == t->val && isSametree(s->left, t->left) && isSametree(s->right, t->right);
        else
            return false;
    }
};