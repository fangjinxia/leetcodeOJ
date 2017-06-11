/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans(0);
        if(!root)
            return ans;
        q.push(root);
        q.push(NULL);
        //ans.push_back(root->val);
        while(!q.empty() && q.front()!=NULL){
            TreeNode* tmp = q.front();
            q.pop();
            
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
            if(q.front() == NULL){
                ans.push_back(tmp->val);
                q.pop();
                q.push(NULL);
                
            }
        }
        return ans;
    }
};