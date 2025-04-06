class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node to handle head swaps cleanly
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy;

        // Traverse the list in pairs
        while (current->next && current->next->next) {
            ListNode* first = current->next;
            ListNode* second = current->next->next;

            // Swap nodes
            first->next = second->next;
            second->next = first;
            current->next = second;

            // Move to the next pair
            current = first;
        }

        return dummy.next;
    }
};
