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
    ListNode* doubleIt(ListNode* head) {
        stack<int>st;
        ListNode* head1 = head;
        while(head1!=NULL){
            st.push(head1->val);
            head1 = head1->next;
        }
        bool carry = false;
        int num;
        stack<int>ans;
        while(!st.empty()){
            num = 2*st.top();
            st.pop();
            if(carry){
                num+=1;
                carry = false;
            }
            if(num>9){
                ans.push(num%10);
                carry = true;
            }
            else{
                ans.push(num);
            }
        }
        if(carry) ans.push(1);
        ListNode* node = new ListNode();
        ListNode* finalans = node;
        while(!ans.empty()){
            ListNode* x = new ListNode(ans.top());
            node->next = x;
            node = node->next;
            ans.pop();
        }
        return finalans->next;
        // ListNode* ans = new ListNode();
        // ListNode* finalans = ans;
        // num = 2*num;
        // string str = to_string(num);
        // for(auto x:str){
        //     ListNode* node = new ListNode(x-'0');
        //     ans->next = node;
        //     ans = ans->next;
        // }
        // return finalans->next;
    }
};