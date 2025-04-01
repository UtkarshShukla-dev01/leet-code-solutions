class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        // Find the length of the list
        ListNode* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }
        
        // Connect the last node to the head to make the list circular
        temp->next = head;
        
        // Find the new head position
        k = k % length;
        int stepsToNewHead = length - k;
        
        // Traverse to the new head
        temp = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            temp = temp->next;
        }
        
        // Set the new head and break the cycle
        ListNode* newHead = temp->next;
        temp->next = nullptr;
        
        return newHead;
    }
};
