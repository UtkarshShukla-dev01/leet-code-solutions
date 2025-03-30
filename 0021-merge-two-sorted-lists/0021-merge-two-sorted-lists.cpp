class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify the process
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        // Iterate through both lists and merge them
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // If one of the lists is not empty, attach the remaining nodes
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        // The head of the merged list is the next of the dummy node
        return dummy->next;
    }
};