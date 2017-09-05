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
    vector<int> v;
    int findSecondMinimumValue(TreeNode* root) {
        get_num(root);
        
        sort(v.begin(), v.end());
        int res = v[0];
        for(int i = 1; i < v.size(); ++i){
            if(v[i] > res)
                return v[i];
        }
        
        return -1;
    }
    
    void get_num(TreeNode* root){
        if(!root)
            return ;
        v.push_back(root->val);
        get_num(root->left);
        get_num(root->right);
    }
};