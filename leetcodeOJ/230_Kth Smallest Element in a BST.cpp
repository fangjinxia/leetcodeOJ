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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v(0);
        genV(root, v);
        sort(v.begin(), v.end());
        return v[k-1];
    }
    
private:
    void genV(TreeNode* root, vector<int>& v){
        if(!root)
            return ;
        v.push_back(root->val);
        genV(root->left, v);
        genV(root->right, v);
    }
};



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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        TreeNode *p = root;
        while(p || !st.empty())
        {
            while(p)
            {
                st.push(p);
                cout << p->val << endl;
                p = p->left;
            }
            p = st.top();
            
            if(--k == 0)
                return p->val;
            st.pop();
            p = p->right;
        }
    }
};