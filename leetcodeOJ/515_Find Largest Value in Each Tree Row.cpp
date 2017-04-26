/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 ///< BFS
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode *> q;
        vector<int> ans;
        if(root == NULL)
            return ans;
            
        q.push(root);
        q.push(NULL);
      //  ans.push_back(root->val);
        while(q.size() != 0 && q.front()){
            int m = INT_MIN;
            while(q.front()){
                TreeNode *tmp = q.front();
                m = max(m, tmp->val);
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            q.pop();
            q.push(NULL);
            ans.push_back(m);
        }
        return ans;
    }
};