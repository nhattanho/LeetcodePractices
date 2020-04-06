/*
  //Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 */
class Solution {
private:
    int remainder;
    ListNode *main;
public:
    Solution(){
        remainder = 0;
        main = NULL;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        remainder = 0;
        ListNode *tail = NULL;
        ListNode *head = NULL;
        int sum = 0;
        while(l1 != NULL || l2 != NULL){
        ListNode *temp = new ListNode(0);
            if(l1 == NULL)
               sum = l2->val + remainder;
            else if (l2 == NULL)
               sum = l1->val + remainder;
            else
               sum = l1->val + l2->val + remainder;
            if(sum >= 10){
               temp->val = sum - 10;
               remainder = 1;
            }else{
               temp->val = sum;
               remainder = 0;
            }
            if(l1 != NULL)
                l1 = l1->next;
            if(l2!= NULL)
                l2 = l2->next;
            if(head == NULL){
                temp->next = NULL;
                head = temp;
                tail = head;
            }
            else{
                temp->next = tail->next;
                tail->next = temp;
                tail = temp;
            }
        }
        if(remainder == 1){
            ListNode *temp = new ListNode(0);
            temp->val = 1;
            temp->next = tail->next;
            tail->next = temp;
            tail = temp;
        }
        return head;
  }
};
