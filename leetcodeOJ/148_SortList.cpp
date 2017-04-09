/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* temp = head;//temp每次移动一步
        ListNode* pre = head;
        ListNode* last = head;//last每次移动两步
        while(last != NULL && last->next != NULL){
            pre = temp;
            temp = temp->next;
            last = last->next;
            last = last->next;
        }
        pre->next = NULL;
        ListNode* right = sortList(temp);
        ListNode* left = sortList(head);
        
        return merge(left, right);
    }
    
private:
    ListNode* merge(ListNode* left, ListNode* right){
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;
        
        if(left->val < right->val){
            left->next = merge(left->next, right);
            return left;
        }
        else{
            right->next = merge(left, right->next);
            return right;
        }
            
    }
};