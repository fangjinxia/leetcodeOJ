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
    int minDepth(TreeNode* root) {
        int max = INT_MAX;
         if(root==NULL){
            return 0;
        }
        int* p = &max;
        maxDpt(root, 0, p);
        return max;
    }
    
private:
    
    void maxDpt(TreeNode* root, int dep, int* p){
        if(root==NULL){
            return;
        }
        dep++;
        if(!root->left && !root->right){
            if(*p > dep){
                *p = dep;
                //cout<<*p<<endl;
            }
        }
        
        maxDpt(root->left, dep, p);
        maxDpt(root->right, dep, p);
        dep--;
    }
};