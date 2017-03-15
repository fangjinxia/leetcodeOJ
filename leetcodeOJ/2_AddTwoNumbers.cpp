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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prehead = (ListNode*)malloc(sizeof(ListNode));
        prehead->val = 0;
        ListNode* head = prehead;

        int c = 0;///<½øÎ»
        while(l1 || l2 || c){
            ListNode* p = (ListNode*)malloc(sizeof(ListNode));
            int sum = ((l1)?l1->val:0) + ((l2)?l2->val:0) + c;
            p->val = sum % 10;
            c = sum / 10;
            p->next = NULL;

            prehead->next = p;
            prehead = prehead->next;

            l1 = (l1)?l1->next:l1;
            l2 = (l2)?l2->next:l2;
        }

        return head->next;
    }
};
