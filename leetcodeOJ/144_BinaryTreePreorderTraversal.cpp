/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  ///<非递归，使用栈，先根节点，再左子树，再右子树
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
            
        stack<struct TreeNode*> s;
        TreeNode* pCur = root;
        while(!s.empty() || pCur){
            if(pCur!=NULL){
                ans.push_back(pCur->val);
                s.push(pCur);
                pCur = pCur->left;
            }
            else{
                pCur = s.top();
                s.pop();
                pCur = pCur->right;
            }
        }
        return ans;
    }
};