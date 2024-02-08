/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void append(ListNode** head, int x)
{
    ListNode* temp = *head;
    ListNode* new_node = new ListNode();
    new_node->val = x;
    new_node->next =NULL;
    if(*head == NULL)
    {
        *head = new_node;
        return;
    }
    ListNode* last = *head;
    while(last->next!=NULL){
        last = last->next;
    }
    last->next = new_node;
    return;

}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* h1 = l1;
        ListNode* h2 = l2;
    while(l1!=NULL and l2!=NULL)
    {

        ListNode* temp = new ListNode();
        temp->val=0;
        temp->next =NULL;
        if(l1->next==NULL and l2->next!=NULL){
            l1->next = temp;
        }
        else if(l2->next == NULL and l1->next!=NULL){
            l2->next =temp;
        }
         l1=l1->next;
         l2=l2->next;
    }
    ListNode* hans = ans;
    ListNode* hh1 =h1;
    ListNode* hh2 =h2;
    int flag=0;
    while(h1!=NULL or h2!=NULL)
    {
        int x;
        if(flag==0)
            x = h1->val + h2->val;
        else if(flag==1)
            x = h1->val + h2->val + 1;
        if(x>=10){
            append(&ans,x%10);
            flag=1;
        }
        else{
            append(&ans,x);
            flag=0;
        }
        h2=h2->next;
        h1=h1->next;
    }
    if(flag==1){
        append(&ans, 1);
    }
        return (hans->next);
    }
};