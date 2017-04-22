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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        ListNode *cur = head;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *pre = newHead;
        
        while(true){
            if(cur->next == NULL){
                if(cur->val == val)
                    pre->next = NULL;
                break;
            }
            else{
                if(cur->val == val)
                    pre->next = cur->next;
                else
                    pre = cur;
                
                cur = cur->next;
            }
        }
        return newHead->next;
    }
};