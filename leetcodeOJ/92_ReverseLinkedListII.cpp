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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* newP = new ListNode(0);
        newP->next = head;
        ListNode* cur = newP;
        for(int i = 0; i < m-1; i++){
            cur = cur->next;
        }
        ListNode* pre = cur;
        cur = cur->next;
        for(int i = 0; i < n - m; i++){
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        
        return newP->next;
    }
};