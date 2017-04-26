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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int ans = root->val;
        while(!q.empty() && q.front()){
           // TreeNode *node = q.front();
            ans = (q.front())->val;
            while(q.front()){
                TreeNode *tmp = q.front();
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            q.pop();
            q.push(NULL);
        }
        return ans;
    }
};