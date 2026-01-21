/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Step 1: Create two pointers
        // fast will move n steps ahead of slow
        ListNode *fast = head;
        ListNode *slow = head;

        // Step 2: Move fast pointer n steps forward
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Step 3: If fast becomes NULL
        // That means we need to delete the first node
        // (because n == length of list)
        if(fast == nullptr) {
            return head->next;
        }

        // Step 4: Move both pointers until fast reaches last node
        // fast->next == NULL means fast is at last node
        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 5: slow is just before the node to be deleted
        // Skip the nth node from end
        slow->next = slow->next->next;

        // Step 6: Return head of the modified list
        return head;
    }
};
