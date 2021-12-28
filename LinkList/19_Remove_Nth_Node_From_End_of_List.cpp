class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*>m(1, NULL);/*space O(n)*/
        ListNode *move = head;
        int count = 0;
        while(move!=NULL){ /*Time O(n)*/
            count++;
            m.push_back(move);
            move = move->next;
        }
        m.push_back(NULL);
        int index = count - n;
        if(index == 0) return head->next;
        m[index]->next = m[index+2];
        return head;
    }
};

/*Another approach without using extra space*/
