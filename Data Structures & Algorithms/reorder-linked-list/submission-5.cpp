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
    void reorderList(ListNode* head) {
        ListNode* first = head;
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = second;
        
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        second = prev;
        ListNode* tail = first;
        ListNode* tmp1 = nullptr;
        ListNode* tmp2 = nullptr;

        while (second) {
            tmp1 = first->next;
            tmp2 = second->next;
            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};
