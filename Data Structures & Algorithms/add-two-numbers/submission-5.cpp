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

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        int div = 0;

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        while(l1 || l2 || div) {
            int val1 = (l1) ? l1->val : 0;
            int val2 = (l2) ? l2->val : 0;
            int sum = val1 + val2 + div;
            int ost = sum % 10;
            div = sum / 10;

            tail->next = new ListNode(ost);
            tail = tail->next;

            if (l1)
            l1 = l1->next;
            if (l2)
            l2 = l2->next;
        }
        return dummy->next;
    }
};
