class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //check if head is empty
        if(head == NULL) return NULL;
        
        // low and fast pointer
        ListNode* low;
        ListNode* fast;
        low = head->next;
        if(low == NULL) return NULL;
        
        fast = low->next;
        if(fast == NULL) return NULL;
        
        // run low and fast => meet at some point
        while( (fast != NULL && low != NULL) && low != fast){
            low = low->next;
            fast = fast->next;
            if(fast != NULL) fast = fast->next;
            else return NULL;
        }
        
        if(fast == NULL || low == NULL) return NULL;
        
        // reset low, and continue running both of them one step per each step
        low = head;
        while(low != fast){
            low = low->next;
            fast = fast->next;
        }
        return fast;
    }
};
