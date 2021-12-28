/*Using one pointer to find the length of List first*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        if(count == 1) return head;
        int mid = count/2 + 1;
        temp = head;
        count = 1;
        while(temp!=NULL){
            temp = temp->next;
            count++;
            if(count == mid) return temp;
        }
        return temp;
    }
};

/*Better solution by using the teachnique likes Floyd's Cycle Detection*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* low = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            low = low->next;
            fast = fast->next->next;
        }
        return (fast->next==NULL)?low:low->next;

    }
};

/*Other way using data structure: map or vector are fine*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        unordered_map<int, ListNode*>m; /*index, pointer <=> space O(n)*/    
        int count = 0;
        while(head != NULL){ /*Time complexity O(n)*/
            m[count++] = head;
            head = head->next;
        }
        int index = count/2;
        return m[index];
    }
};
