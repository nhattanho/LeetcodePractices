class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(slow->next && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return fast->next == NULL ? slow : slow->next;
    }
        
};
