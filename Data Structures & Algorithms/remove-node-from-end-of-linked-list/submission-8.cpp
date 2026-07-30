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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int cnt = 0;

        while (curr) {
            curr = curr->next;
            cnt++;
        }

        if (n == cnt) {
            head = head->next;
            return head;
        }
        curr = head;
        ListNode* prev = nullptr;

        while (curr) {
            if (cnt == n) {
                prev->next = curr->next;    
                break;
            }

            prev = curr;
            curr = curr->next;
            --cnt;
        }
        return head;
    }
};
