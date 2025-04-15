class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (head != nullptr) {
            // Check for start of duplicates
            if (head->next != nullptr && head->val == head->next->val) {
                // Skip all nodes with this value
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                // Connect prev with the node after the duplicate sequence
                prev->next = head->next;
            } else {
                // No duplicate, move prev
                prev = prev->next;
            }
            // Always move head forward
            head = head->next;
        }

        return dummy->next;
    }
};
