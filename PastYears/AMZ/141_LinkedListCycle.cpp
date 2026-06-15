class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode *low, *fast;
        low = head->next;
        fast= low->next;
        if(fast == NULL) return false;
        while(low != NULL && fast != NULL && low != fast){
            low = low->next;
            fast = fast->next;
            if(fast == NULL) return false;
            fast = fast->next;
        }
        if(fast == NULL || low == NULL) return false;
        return true;
    }
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode* move = head;
        unordered_map<ListNode*, int> l;
        while(move != NULL){
            if(l[move] != 0) return true;
            l[move]++;
            move = move->next;
        }
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode* move = head;
        list<ListNode*> l;
        while(move != NULL){
            auto it = find(l.begin(), l.end(), move);
            if(it != l.end()) return true;
            l.push_front(move);
            move = move->next;
        }
        return false;
    }
};
