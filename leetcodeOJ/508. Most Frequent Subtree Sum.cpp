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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        
        unordered_map<int, int> counts;
        int maxCount = 0;
        countSubTreeSums(root, counts, maxCount);
        
        for(auto m : counts){
            if(m.second == maxCount)
                ans.push_back(m.first);
        }
        return ans;
    }
    
    int countSubTreeSums(TreeNode* root, unordered_map<int, int>& counts, int& maxCount){
        if(root == NULL)
            return 0;
        int sum = root->val;
        sum += countSubTreeSums(root->left, counts, maxCount);
        sum += countSubTreeSums(root->right, counts, maxCount);
        
        ++counts[sum];
        maxCount = max(maxCount, counts[sum]);
        return sum;
    }
};