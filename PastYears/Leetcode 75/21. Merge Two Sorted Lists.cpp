class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *temp = new ListNode();
        ListNode *run = temp;
        
        while(l1 && l2){
            if(l1->val <= l2->val){
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        if(l1 == NULL) temp->next = l2;
        else temp->next = l1;
        return run->next;
    }
};
