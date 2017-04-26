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
    ListNode *detectCycle(ListNode *head) {
        ListNode *pre = head, *cur = head;
        while(cur && cur->next){
            if(cur == NULL)
                return NULL;
            cur = cur->next;
            cur = cur->next;
            pre = pre->next;
            if(cur == pre){
                ListNode *fp = head;
                while(fp != pre){
                    pre = pre->next;
                    fp = fp->next;
                }
                return fp;
                
            }
        }
        return NULL;
    }
};