/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //思路：寻找中间节点
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return create(head, NULL);
    }

private:
    TreeNode* create(ListNode* head, ListNode* tail){
        if(head == tail)
            return NULL;
        if(head->next == tail){
            TreeNode* node = new TreeNode(head->val);
            return node;
        }
        
        ListNode* mid = head;
        ListNode* temp = head;
        while(temp != tail && temp->next != tail){
            mid = mid->next;
            temp = temp->next->next;
        }
        
        TreeNode* root = new TreeNode(mid->val);
        root->left = create(head, mid);
        root->right = create(mid->next, tail);
        
        return root;
    }
};