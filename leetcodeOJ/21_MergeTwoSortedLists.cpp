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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* prehead = (ListNode*)malloc(sizeof(ListNode));
        prehead->val = 0;
        prehead->next = NULL;
        ListNode* head = prehead;

        while(l1 || l2){
            int num1 = (l1)?l1->val:INT_MAX;
            int num2 = (l2)?l2->val:INT_MAX;

            if(num1 < num2){
                prehead->next = l1;
                prehead = l1;
                l1 = l1->next;
            }

            else{
                prehead->next = l2;
                prehead = l2;
                l2 = l2->next;
            }
        }
        return head->next;
    }
};
