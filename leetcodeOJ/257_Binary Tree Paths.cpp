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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL)
            return ans;
        string re = "" + to_string(root->val);
        genPaths(root, ans, re);
        //genPaths(root->right, ans, re);
        return ans;
    }
private:
    void genPaths(TreeNode* root, vector<string> &ans, string s){
        if(root->left == NULL && root->right == NULL){
            ans.push_back(s);
            return ;
        }
        if(root->left){
            string s1 = s;
            s1 += "->" + to_string(root->left->val);
            genPaths(root->left, ans, s1);
        }
        if(root->right){
            string s2 = s;
            s2 += "->" + to_string(root->right->val);
            genPaths(root->right, ans, s2);
        }
    }
};