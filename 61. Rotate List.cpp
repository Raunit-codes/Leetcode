/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int size(ListNode* head) {
        ListNode* temp = head;
        int size = 0;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        return size;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;

        int length = size(head);

        if (k % length == 0) {
            return head;
        }

        k = k % length;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = head;
        ListNode* temp = head;
        for (int i = 1; i < length - k; i++) {
            temp = temp->next;
        }
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};
