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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *cur = newHead;
        ListNode *pre = newHead;
        
        if(head == NULL || head->next == NULL)
            return head;
        
        ///<计算出一共多少个节点
        ListNode *tail = head;
        int cnt = 0;
        while(tail){
            tail = tail->next;
            cnt++;
        }
        
        while(cnt >= k){
            ///<逆转
            cur = pre->next;
            
            for(int i = 1; i < k; i++){
                ListNode *temp = cur->next;
                cur->next = temp->next;
                temp->next = pre->next;
                pre->next = temp;
            }
            pre = cur;
            cnt -= k;
        }
        
        return newHead->next;
    }
};