/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 ///<非递归，使用栈，先左子树，再根节点，再右子树
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        // if(!root)
        //     return ans;
        
        stack<struct TreeNode*> s;
        while(root || !s.empty()){
            if(root != NULL){
                s.push(root);
                root = root->left;
            }
            else{
                root = s.top();
                cout<<root->val<<endl;
                ans.push_back(root->val);
                s.pop();
                root = root->right;
            }
        }
        
        return ans;
    }
};