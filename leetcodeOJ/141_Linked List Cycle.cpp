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
    bool hasCycle(ListNode *head) {
        ListNode *pre = head;
        ListNode *cur = head;
        while(cur && cur->next){
            if(cur == NULL)
                return false;
            cur = cur->next;
            cur = cur->next;
            pre = pre->next;
            if(cur == pre)
                return true;
        }
        return false;
    }
};