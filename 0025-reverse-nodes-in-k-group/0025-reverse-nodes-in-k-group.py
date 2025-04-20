# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # Check if there are at least k nodes to reverse
        curr = head
        count = 0
        while curr and count < k:
            curr = curr.next
            count += 1

        if count == k:
            # Reverse first k nodes
            prev = None
            curr = head
            for _ in range(k):
                nxt = curr.next
                curr.next = prev
                prev = curr
                curr = nxt
            
            # head is now the tail after reversing; connect it with the next reversed group
            head.next = self.reverseKGroup(curr, k)

            # prev is the new head of this k-group
            return prev

        # Less than k nodes, return as is
        return head
