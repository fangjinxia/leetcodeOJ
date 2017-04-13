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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL)
            return head;
        
        ListNode *p = head, *pre = head, *pp = head;
        int len = 1;
        while(p->next){
            len++;
            p = p->next;
        }
        p = head;
        for(int i = 0; i < k%len; i++){
            if(pp->next == NULL)
                pp = head;
            else
                pp = pp->next;
        }
        cout << pp->val;
        while(pp->next != NULL){
            pp = pp->next;
            pre = p;
            p = p->next;
        }
        pp->next = head;
        pre = p->next;
        p->next = NULL;
        return pre;       
    }
};