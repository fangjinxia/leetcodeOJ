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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *evenNode = new ListNode(0);
        ListNode *evenHead = evenNode;
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *cur = head, *oddNode = head;
        while(cur && cur->next){
            evenNode->next = cur->next;
            evenNode = evenNode->next;
            cur = cur->next;
            if(cur->next == NULL){
                cur = cur->next;
                break;
            }
            oddNode->next = cur->next;
            oddNode = oddNode->next;
            cur = cur->next;
        }
        
        if(cur != NULL){
            oddNode->next = cur;
            oddNode = oddNode->next;
            evenNode->next = NULL;
        }
        
        oddNode->next = evenHead->next;
        return head;
    }
};