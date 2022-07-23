class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *run = head, *pre = NULL;
        while(head->next != NULL){
            run = head->next;
            head->next = pre;
            pre = head;
            head = run;
        }
        head->next = pre;
        return head;
    }
};
