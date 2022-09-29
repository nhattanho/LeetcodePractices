class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*>m;
        ListNode *move = head;
        int count = 0;
        while(move!=NULL){
            count++;
            m.push_back(move);
            move = move->next;
        }
        m.push_back(NULL);
        int index = count - n;
        if(index == 0) return head->next;
        m[index-1]->next = m[index+1];
        return head;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> v;
        ListNode *move = head;
        while(move!=NULL){
            v.push_back(move);
            move = move->next;
        }
        if(v.size() == n) return head->next;
        int index = v.size()-n-1;
        
        v[index]->next = v[index]->next->next;
        return head;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *move = head;
        int count = 0;
        while(move != NULL){
            count++;
            move = move->next;
        }
        int pos = count - n;
        if(pos == 0) return head->next;
        count = 0;
        move = head;
        
        while(move!=NULL){
            count++;
            if(count == pos){
                move->next = move->next->next;    
                return head;
            }
            move = move->next;
        }
        return head;
    }
};

/*Kept the distance between slow and fast pointer is n*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *s = head, *f = head, *pre = head;
        for(int i = 0; i <n; i++){
            f = f->next;
        }
        while(f != NULL){
            pre = s;
            s = s->next;
            f = f->next;
        }
        pre->next = s->next;
        return (pre == s)?head->next:head;
    }
};
