/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //��ת������ԭ����Ա�
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //����ԭ����
        ListNode *current = head;
        ListNode *newList = NULL;//�������ͷָ��
        ListNode *tail = NULL;//�������βָ��
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
        
        //��ת����
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
        
        //�Ա�������
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