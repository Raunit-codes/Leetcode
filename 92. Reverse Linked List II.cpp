class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == nullptr || left == right)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        // Reach the node just before 'left'
        ListNode* prev = &dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // First node of the portion to reverse
        ListNode* curr = prev->next;

        // Reverse the sublist
        for (int i = 0; i < right - left; i++) {

            ListNode* next = curr->next;

            curr->next = next->next;

            next->next = prev->next;

            prev->next = next;
        }

        return dummy.next;
    }
};
