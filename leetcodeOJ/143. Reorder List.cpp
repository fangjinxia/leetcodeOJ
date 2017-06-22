/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Ë¼Â·£º
 //split the list from the middle into two lists. 
 //One from head to middle, and the other from middle to the end. 
 //Then we reverse the second list. 
 //Finally we merge these two lists. 
 //O(n) time complexity and O(1) space complexity.
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return;
        
        ListNode *cur = head, *tail = head;
        while(tail && tail->next && tail->next->next){
            cur = cur->next;
            tail = tail->next->next;
        }
        
        ListNode* mid = cur->next;
        cur->next = NULL;
        cur = head;
        
        //Äæ×ª
        ListNode* q1=mid, *q2,*q3;
        if(mid->next){
            q1=mid;
            q2=mid->next;
            while(q2){
                q3=q2->next;
                q2->next=q1;
                q1=q2;
                q2=q3;
                
            }
            mid->next=NULL;
        }
        tail=q1;
        
        ListNode* s = cur;
        cur = cur->next;
        while(cur && tail){
            s->next = tail;
            s = s->next;
            tail = tail->next;
            
            s->next = cur;
            s = s->next;
            cur = cur->next;
        }
        if(cur)
            s->next = cur;
        if(tail)
            s->next = tail;
    }
};