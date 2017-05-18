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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return NULL;
        //�ҵ�β��
        ListNode *tailA = headA;
        while(tailA->next){
            tailA = tailA->next;
        }
        
        //��headA��β����headB���׶������������γɻ�
        ListNode *tail = tailA;
        tail->next = headB;
        
        //�����
        ListNode *cur = headA;
        tail = headA;
        while(tail && tail->next){
            cur = cur->next;
            tail = tail->next->next;
            if(cur == tail)
                break;
        }
        if(tail == NULL || tail->next==NULL) {//û�н���
            tailA->next = NULL;
            return NULL;
        }
            
        cur = headA;
        while(cur != tail){
            cur = cur->next;
            tail = tail->next;
        }
        
        //�ָ�����Դ����
        tailA->next = NULL;
        
        return cur;
    }
};