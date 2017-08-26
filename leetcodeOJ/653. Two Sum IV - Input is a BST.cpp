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
    bool findTarget(TreeNode* root, int k) { 
        ///<中序遍历，vector中的数为有序
        inorder(root);
        
        int lo = 0; 
        int hi = nums.size()-1;
        while(lo < hi){
            int tmp = nums[lo] + nums[hi];
            if(tmp == k)
                return true;
            if(tmp < k)
                ++lo;
            else 
                --hi;
        }
        return false;
    }
    
private:
    vector<int> nums;
    
    void inorder(TreeNode* root){
        if(!root)
            return ;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
    
    
};