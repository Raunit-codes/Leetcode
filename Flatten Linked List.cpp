class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};
class Solution {
public:

    // Merge two sorted bottom-linked lists
    Node* merge(Node* a, Node* b) {
        if (a == nullptr)
            return b;

        if (b == nullptr)
            return a;

        Node* result;

        if (a->data <= b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        }
        else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        return result;
    }

    Node* flatten(Node* head) {

        // Only one column remains
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // First flatten everything to the right
        head->next = flatten(head->next);

        // Merge current column with flattened right side
        head = merge(head, head->next);

        return head;
    }
};
