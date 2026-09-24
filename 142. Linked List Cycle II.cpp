/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool hascycle = false;

        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                hascycle = true;
                break;
            }
        }
        
        if(!hascycle){
            return nullptr;
        }
        
        slow = head;
        while(fast!=slow){
            slow = slow->next;
            fast = fast->next;
        }
        
        return fast;
    }
};
