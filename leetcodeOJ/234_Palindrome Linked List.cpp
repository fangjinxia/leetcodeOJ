/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //逆转链表，与原链表对比
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //复制原链表
        ListNode *current = head;
        ListNode *newList = NULL;//新链表的头指针
        ListNode *tail = NULL;//新链表的尾指针
        while(current != NULL){
            if(newList == NULL){
                newList = new ListNode(current->val);
                tail = newList;
            }
            else{
                tail->next = new ListNode(current->val);
                tail = tail->next;
            }
            current = current->next;
        }
        
        //逆转链表
        ListNode *newP = new ListNode(0);
        newP->next = head;
        ListNode *pre = newP;
        ListNode *cur = head;
        while(cur && cur->next){
            ListNode *temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        head = newP->next;
        
        //对比两链表
        while(head != NULL){
            if(head->val != newList->val){
                return false;
            }
            else{
                head = head->next;
                newList = newList->next;
            }
        }
        return true;
    }
};