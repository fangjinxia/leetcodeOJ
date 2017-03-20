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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ///<˼·����������ָ�룬��ͷ��β��ɨ������ָ�������n-1,����һ��ָ��ɨ��β��ʱ���ڶ���ָ���������Ҫremove��node
        
        ListNode* p1 = head;
        if(p1->next == NULL && n == 1){
            return NULL;
        }
        for(int i = 0; i < n; i++){
            p1 = p1->next;
        }
        ListNode* p2 = head;
        ListNode* pre = head;
        while(p1){
            p1 = p1->next;
            pre = p2;
            p2 = p2->next;
        }
        
        if(p2 == head){
            return head->next;///<�Ƴ���һ��
        }
        
        else{
            pre->next = (pre->next)->next;
        }
        
        return head;
        
    }
};