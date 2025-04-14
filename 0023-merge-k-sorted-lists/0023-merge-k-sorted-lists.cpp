#include <queue>
#include <vector>
using namespace std;

class Compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-heap: node with smaller value has higher priority
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        // Insert the head of each list into the heap
        for (ListNode* node : lists) {
            if (node) {
                minHeap.push(node);
            }
        }

        ListNode dummy(0);  // Dummy head node
        ListNode* current = &dummy;

        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            current->next = smallest;
            current = current->next;

            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }

        return dummy.next;
    }
};
