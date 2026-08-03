/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        Node* dummy = new Node(0);
        Node* tail = dummy;

        unordered_map<Node*, Node*> um;

        while (curr) {
            Node* node = new Node(curr->val);
            um[curr] = node;
            curr = curr->next;
            tail->next = node;
            tail = tail->next;
        }
        
        Node* new_head = dummy->next;
        curr = head;
        while (new_head && curr) {
            new_head->random = um[curr->random];
            curr = curr->next;
            new_head = new_head->next;
        }

        return dummy->next;
    }
};
