class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        // STEP 1: Create copy nodes and insert them
        // immediately after their original nodes.
        Node* curr = head;

        while (curr != nullptr) {
            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        // STEP 2: Set random pointers of copied nodes.
        curr = head;

        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        // STEP 3: Separate original and copied lists.
        curr = head;
        Node* newHead = head->next;

        while (curr != nullptr) {
            Node* copy = curr->next;

            curr->next = copy->next;

            if (copy->next != nullptr) {
                copy->next = copy->next->next;
            }

            curr = curr->next;
        }

        return newHead;
    }
};
