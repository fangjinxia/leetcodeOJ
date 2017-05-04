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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
      
        vector<int> num1(0), num2(0);
        while(l1){
            num1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2){
            num2.push_back(l2->val);
            l2 = l2->next;
        }
        
        vector<int> v(0);
        int c = 0, n1 = 0, n2 = 0; //½øÎ»
        for(int i = num1.size()-1, j = num2.size()-1; i >= 0 || j >= 0; i--, j--){
            n1 = (i>=0) ? num1[i] : 0;
            n2 = (j>=0) ? num2[j] : 0;
            n1 = n1+n2+c;
            v.push_back(n1%10);
            c = n1 / 10;
        }
        if(c != 0){
            v.push_back(c);
        }
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        
        for(int i = v.size()-1; i >= 0; i--){
            ListNode *tmp = new ListNode(v[i]);
            cur->next = tmp;
            cur = cur->next;
        }
        cur->next = NULL;
        return head->next;   
    }
};