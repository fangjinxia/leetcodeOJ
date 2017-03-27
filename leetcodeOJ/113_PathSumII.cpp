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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        vector<int> v;
        rev(ans, v, 0, root, sum);
        return ans;
    }
    
private:
    void rev(vector<vector<int>>& ans, vector<int>& v, int temp, TreeNode* root, int sum){
        if(root==NULL)
            return;
        temp += root->val;
        v.push_back(root->val);
        if(!root->left && !root->right){
            if(temp == sum)
                ans.push_back(v);
        }
        
        rev(ans, v, temp, root->left, sum);
        rev(ans, v, temp, root->right, sum);
        v.pop_back();    
    }
};