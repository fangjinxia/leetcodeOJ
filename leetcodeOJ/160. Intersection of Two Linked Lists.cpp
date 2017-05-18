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
        //找到尾端
        ListNode *tailA = headA;
        while(tailA->next){
            tailA = tailA->next;
        }
        
        //将headA的尾端与headB的首端连接起来，形成环
        ListNode *tail = tailA;
        tail->next = headB;
        
        //找入口
        ListNode *cur = headA;
        tail = headA;
        while(tail && tail->next){
            cur = cur->next;
            tail = tail->next->next;
            if(cur == tail)
                break;
        }
        if(tail == NULL || tail->next==NULL) {//没有交集
            tailA->next = NULL;
            return NULL;
        }
            
        cur = headA;
        while(cur != tail){
            cur = cur->next;
            tail = tail->next;
        }
        
        //恢复两个源链表
        tailA->next = NULL;
        
        return cur;
    }
};