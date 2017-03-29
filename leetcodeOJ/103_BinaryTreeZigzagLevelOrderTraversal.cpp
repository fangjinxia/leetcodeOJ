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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        int flag = 0;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node){
                flag ^= 1;
                if(flag == 0){
                    reverse(v.begin(), v.end());
                }
                ans.push_back(v);
                v.resize(0);
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                v.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};