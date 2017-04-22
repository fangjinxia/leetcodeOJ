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
    ListNode* swapPairs(ListNode* head) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *cur = head;
        ListNode *pre = newHead;
        
        if(head == NULL || head->next == NULL)
            return head;
        while(cur != NULL && cur->next != NULL){
            ListNode *tmp = cur->next;
            
            pre->next = tmp;
            cur->next = tmp->next;
            tmp->next = cur;
            
            pre = cur;
            cur = cur->next;
        }
        return newHead->next;
    }
};