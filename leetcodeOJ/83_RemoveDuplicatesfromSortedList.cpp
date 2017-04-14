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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        if(p1 == NULL || p1->next == NULL)
            return head;
        
        ListNode* pre = p2;
        ListNode* tail = p1;
        p2 = p2->next;
        for(p1 = p1->next; p2 != NULL; pre = p2, p2 = p2->next){
            if(p2->val == pre->val)
                continue;
            else{
                p1->val = p2->val;
                tail = p1;
                p1 = p1->next;
            }
        }
        tail->next = NULL;
        return head;
    }
};