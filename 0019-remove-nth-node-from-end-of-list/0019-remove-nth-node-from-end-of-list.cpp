class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Create a dummy node before the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 2: Set both slow and fast to dummy
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Step 3: Move fast n steps ahead
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        // Step 4: Move both fast and slow until fast reaches end
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 5: Remove the nth node from end
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        // Step 6: Return the new head
        ListNode* newHead = dummy->next;
        delete dummy;  // Free dummy node
        return newHead;
    }
};
