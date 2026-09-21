class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverseList(head);

        // If the target is the head of the reversed list
        if (n == 1) {
            head = head->next;
        } else {
            ListNode* curr = head;

            // Reach the node immediately before the target
            for (int i = 1; i < n - 1; i++) {
                curr = curr->next;
            }

            // Skip the target node
            curr->next = curr->next->next;
        }

        return reverseList(head);
    }
};
