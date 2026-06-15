class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode* move = head;
        while(move != NULL){
            len++;
            if(move->next == NULL) break;
            move = move->next;
        }
        if(len == 0) return NULL;
        k %= len;
        if (k == 0) return head;
        ListNode* temp = head;
        while(temp != NULL){
            len--;
            if(len == k){
                ListNode* tempHead = temp->next;
                temp->next = NULL;
                move->next = head;
                head = tempHead;
                break;
            }
            temp = temp->next;  
        }
        return head;
    }
};
