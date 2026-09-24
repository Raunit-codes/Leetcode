class Solution {
public:
    void removeCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // Step 1: Detect cycle
        ListNode* slow = head;
        ListNode* fast = head;

        bool hasCycle = false;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        // No cycle
        if (!hasCycle) {
            return;
        }

        // Step 2: Find beginning of cycle
        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // slow/fast = beginning of cycle

        // Step 3: Find last node of cycle
        while (fast->next != slow) {
            fast = fast->next;
        }
        // break cycle
        fast->next = nullptr;

    }
};
