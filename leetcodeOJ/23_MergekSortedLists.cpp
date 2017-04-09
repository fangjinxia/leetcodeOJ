/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //思路：进行两两排序
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0)
            return NULL;
        if(n == 1)
            return lists[0];
            
        ListNode* ans = lists[0];
        for(int i = 1; i < n; i++){
            ans = merge(ans, lists[i]);
        }
        
        return ans;    
    }
    
private:
    ListNode* merge(ListNode* left, ListNode* right){
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }
        
        if(left->val < right->val){
            left->next = merge(left->next, right);
            return left;
        }
        else{
            right->next = merge(left, right->next);
            return right;
        }
    }
};