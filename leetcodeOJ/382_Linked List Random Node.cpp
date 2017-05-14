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
    ListNode *newHead = new ListNode(0);
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        newHead->next = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ans = -1;
        int cnt = 0;
        ListNode *tail = newHead->next;
        while(tail){
            cnt++;
            if(cnt == 1)
                ans = tail->val;
            else
                if((rand() % cnt) == 0)
                    ans = tail->val;
            
            tail = tail->next;
        }
        return ans;
    }

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */