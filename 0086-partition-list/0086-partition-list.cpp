class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Create two dummy nodes for before and after partitions
        ListNode* beforeHead = new ListNode(0);
        ListNode* afterHead = new ListNode(0);

        // Pointers to build the two lists
        ListNode* before = beforeHead;
        ListNode* after = afterHead;

        // Traverse the original list
        while (head != nullptr) {
            if (head->val < x) {
                // Add node to before list
                before->next = head;
                before = before->next;
            } else {
                // Add node to after list
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }

        // Terminate the after list
        after->next = nullptr;

        // Connect before list with after list
        before->next = afterHead->next;

        // Return head of the modified list
        return beforeHead->next;
    }
};
