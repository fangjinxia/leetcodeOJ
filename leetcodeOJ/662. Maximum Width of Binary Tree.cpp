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
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> lefts;
        dfs(root, 0, 1, lefts);
        return max_width;        
    }
    
    void dfs(TreeNode* root, int depth, int id, vector<int>& lefts){
        if(root == NULL)
            return ;
        if(depth >= lefts.size()){
            lefts.push_back(id);//记录每一层最左边id
        }
        max_width = max(max_width, id - lefts[depth] + 1);
        dfs(root->left, depth+1, id*2, lefts);
        dfs(root->right, depth+1, id*2+1, lefts);
    }
    
private:
    int max_width = 0;
};