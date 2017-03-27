/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 ///<思路：先根再右最后左(如前序遍历)，最后逆转
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        stack<TreeNode*> s;
        TreeNode* pCur = root;
        while(!s.empty() || pCur){
            if(pCur){
                s.push(pCur);
                ans.push_back(pCur->val);
                pCur = pCur->right;
            }
            else{
                pCur = s.top();
                s.pop();
                pCur = pCur->left;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};