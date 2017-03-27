/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  ///<�ǵݹ飬ʹ��ջ���ȸ��ڵ㣬������������������
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