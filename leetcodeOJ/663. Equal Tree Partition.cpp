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
    bool checkEqualTree(TreeNode* root) {
        if(!root)
            return false;
        unordered_set<int> res;
        int left_sum = get_sum(root->left, res);
        int right_sum = get_sum(root->right, res);
        int sum = root->val + left_sum + right_sum;
        
        return (sum % 2 == 0) && res.find(sum / 2) != res.end();
        
    }
    
private:
    int get_sum(TreeNode* root, unordered_set<int>& res){
        if(!root)
            return 0;
        int tmp = root->val + get_sum(root->left, res) + get_sum(root->right, res);
        res.insert(tmp);        
        return tmp;
    }
};