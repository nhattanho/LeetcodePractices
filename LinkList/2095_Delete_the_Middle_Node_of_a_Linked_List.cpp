class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        /*Space O(1)*/
        ListNode *fast = head, *slow = head, *pre = head, *front = slow->next;   
        if(front == NULL) return NULL;
        while(fast!=NULL && fast->next!=NULL){ /*Time Complexity O(n)*/
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
            front = slow->next;
        }
        pre->next = front;
        delete(slow);
        return head;
    }
};
