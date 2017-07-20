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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v(0);
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){      
            if(q.front() == NULL){
                q.pop();
                continue;
            }
            double num = 0;
            int k = 0;
            while(q.front()){
                TreeNode *tmp = q.front();
                q.pop();
                num += tmp->val;
                ++k;
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            q.push(NULL);
            v.push_back((double)num/k);
        }
        
        return v;
    }
};