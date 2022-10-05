/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* head = new ListNode();
        if(list1->val <= list2->val){
            head->next = list1;
            list1 = list1->next;
        } 
        else {
            head->next = list2;
            list2 = list2->next;
        }
        ListNode* pre = head->next;
        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                pre->next = list1;
                pre = list1;
                list1 = list1->next;
            }else{
                pre->next = list2;
                pre = list2;
                list2 = list2->next;
            }
        }
        if(list1 == NULL) pre->next = list2;
        else pre->next = list1;
        return head->next;
    }
};

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
