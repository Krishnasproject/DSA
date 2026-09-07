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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int digit1;
        int digit2;
        int carry = 0;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        ListNode* res;
        while(l1 || l2){
            if(l1 != nullptr)
        {
            digit1 = l1->val;
        }else
            digit1 = 0;


        if(l2 != nullptr)
        {
            digit2 = l2->val;
        }else
            digit2 = 0;
        
            int total = digit1 + digit2 + carry ;

            int digit = total % 10;
            carry = total/ 10;
            
            curr->next = new ListNode(digit);
            curr = curr->next;

            if(l1 != nullptr)
                l1 = l1->next;
            if(l2 != nullptr)
                l2 = l2->next;

            if(carry != 0)
                curr->next = new ListNode(carry);
            
        }
        return dummy->next;
    }
};