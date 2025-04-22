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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode();
        ListNode *run = res;
        int remain = 0;
        while(l1 != NULL || l2 != NULL || remain != 0) 
        {
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            int sum = num1 + num2 + remain;
            remain = sum/10;
            sum %= 10;
            run->next = new ListNode(sum);
            run = run->next;
            l1 = l1? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        res = res->next;
        return res;
    }
};
