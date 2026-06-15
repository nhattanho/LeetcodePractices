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

/*Better solution by using the teachnique likes Floyd's Cycle Detection
example we have n nodes, and having 2 starting point. If the first point
<=> fast point jumps 2 steps at each time while second point <=> slow point
jump one step.

So calling x1 is the #steps fast point will have ==> 2x1 = n
x2 is the #steps slow point jump to reach the n => x2 = n
==> x1 = x2/2 = n/2

Therefore, if two point starts as the same time, when the fast point reach
the end, slow point will reach the middle.*/
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

/*More readable*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
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
