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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return create(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    
private:
    TreeNode* create(vector<int>& inorder, vector<int>& postorder, int iSta, int iEnd, int pSta, int pEnd){
        if(iSta > iEnd)
            return NULL;
        TreeNode* node = new TreeNode(postorder[pEnd]);
        int i = iSta;
        for(; i <= iEnd; i++){
            if(inorder[i] == node->val)
                break;
        }
        //注意边界，后四个参数的值
        node->left = create(inorder, postorder, iSta, i-1, pSta, pSta+i-iSta-1);
        node->right = create(inorder, postorder, i+1, iEnd, pSta+i-iSta, pEnd-1);
        return node;
    }
};