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
        ///<思路：设置两个指针，从头往尾巴扫，两个指针距离是n-1,当第一个指针扫到尾巴时，第二个指针就是我们要remove的node
        
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
            return head->next;///<移除第一个
        }
        
        else{
            pre->next = (pre->next)->next;
        }
        
        return head;
        
    }
};