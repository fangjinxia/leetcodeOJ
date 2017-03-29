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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create(nums, 0, nums.size());
    }
    
private:
    TreeNode* create(vector<int>& num, int lo, int hi){
        if(lo >= hi){
            return NULL;
        }
        int mid = lo + (hi-lo)/2;
        TreeNode* root = new TreeNode(num[mid]);
        root->left = create(num, lo, mid);
        root->right = create(num, mid+1, hi);
        
        return root;
    }
};