class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        while(head != NULL){
            ListNode* after = head->next;
            head->next = pre;
            pre = head;
            head = after;
        }
        return pre;
    }
};
