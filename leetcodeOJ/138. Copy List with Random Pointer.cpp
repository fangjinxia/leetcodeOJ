/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
//把每个新的node都插入原始链表中的对应的旧node的后面，
//这样非常方便就能找到新node在新list中的新random pointer，
//最后，拆分旧链表和新链表。 

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *newHead, *l1, *l2;
        if (head == NULL) return NULL;
    
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->random;
            l1->random = l2;
        }
        
        newHead = head->random;
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->random;
            l2->random = l2->next ? l2->next->random : NULL;
        }
        
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->random;
            l1->random = l2->next;
            l2->next = l1->next ? l1->next->random : NULL;
        }
    
        return newHead;
    }
};