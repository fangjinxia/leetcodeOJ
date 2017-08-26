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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //ÖÐÐò±éÀú    
        if(nums.size() == 0)
            return NULL;
        
        return constructTree(nums, 0, nums.size()-1);
    }
    
    TreeNode* constructTree(vector<int>& nums, int low, int high){
        if(low > high)
            return NULL;
        
//         vector<int>::iterator iter = max_element(nums.begin() + low, nums.begin()+high+1);
//         int idx = distance(nums.begin(), iter);
        
        int idx = low;
        for(int i = low; i <= high; ++i){
            if(nums[i] > nums[idx])
                idx = i;
        }
        
    //   cout << idx << endl;
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = constructTree(nums, low, idx-1);
        root->right = constructTree(nums, idx+1, high);
        return root;
        
    }
};