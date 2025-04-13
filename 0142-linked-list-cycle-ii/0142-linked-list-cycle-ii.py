class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = fast = head

        # Step 1: Detect if a cycle exists using slow and fast pointers
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                break
        else:
            # No cycle
            return None

        # Step 2: Find the entry point of the cycle
        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next

        return slow  # This is the start of the cycle
