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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
private:
    TreeNode* create(vector<int>& preorder, vector<int>& inorder, int pSta, int pEnd, int iSta, int iEnd){
        if(pSta > pEnd){
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[pSta]);
        int i = iSta;
        for(; i <= iEnd; i++){
            if(inorder[i] == node->val){
                break;
            }
        }
        
        node->left = create(preorder, inorder, pSta+1, pSta+i-iSta , iSta, iSta+i);
        node->right = create(preorder, inorder, pSta+i-iSta+1, pEnd , i+1, iEnd);
        return node;
    }
};