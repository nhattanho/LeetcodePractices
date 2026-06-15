class Solution {
public:
    bool isCycle(ListNode *head, ListNode **remark){
        while(head == NULL) return false;
        ListNode *fast = head, *slow = head;
        while(slow->next != NULL && fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) {
                *remark = fast;
                return true;
            };
        }
        return false;
    }
    
    ListNode *detectCycle(ListNode *head){
        ListNode *remark = NULL;
        if(!isCycle(head, &remark)) return NULL;
        ListNode *slow = head;
        while(true){
            if(slow == remark) return slow;
            slow = slow->next;
            remark = remark->next;
        }
        return NULL;   
    }
};
