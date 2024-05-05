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
    void swap(ListNode* n1, ListNode* n2){
        int temp = n1->val;
        n1->val=n2->val;
        n2->val=temp;
        return;
    }
    void deleteNode(ListNode* node) {
        ListNode* x = node;
        while(node->next!=NULL){
            swap(node, node->next);
            x = node;
            node = node->next;
        }
        x->next = NULL;
        // free(node);
        return;
    }
};