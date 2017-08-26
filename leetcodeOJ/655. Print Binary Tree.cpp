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
    vector<vector<string>> printTree(TreeNode* root) {
        int height = dealTree(root);//行
        int width =  pow(2, height) - 1;//列
     //   cout << width << endl;
        vector<vector<string>> res(height, vector<string>(width, ""));
        if(!root)
            return res;
        
        fill(res, root, 0, 0, width-1);//从第0行开始, 第0列到第width-1列
        return res;
    }
    
    void fill(vector<vector<string>>& res, TreeNode* root, int k, int lft, int rht){
        if(k > res.size() || root == NULL)
            return;
        string s = to_string(root->val);
     //   cout << lft << " " << rht << endl;
        int col = lft + (rht - lft)/2;
        res[k][col] = s;
        if(root->left){
            fill(res, root->left, k+1, lft, col-1);
        }
        if(root->right){
            fill(res, root->right, k+1, col+1, rht);
        }
    }
    
    int dealTree(TreeNode* root){
        if(!root)
            return 0;
        return 1 + max(dealTree(root->left), dealTree(root->right));
    }
    
    int pow(int a, int x){
        if(x == 1)
            return a;
        else if(x == 0)
            return 1;
        else{
            if(x & 1){//x为奇数
                return a * pow(a*a, x>>1);
            }
            else{
                return pow(a*a, x>>1);
            }
        }
    }
};