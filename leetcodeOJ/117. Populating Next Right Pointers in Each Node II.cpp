/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
 //BFS
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return ;
            
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty() && q.front()){
            TreeLinkNode *tmp = q.front();
            q.pop();
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
            
            while(q.front()){
                TreeLinkNode *pNode = q.front();
                q.pop();
                tmp->next = pNode;
                tmp = pNode;
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            q.pop();
            q.push(NULL);
        }
    }
};