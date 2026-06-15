/*For this problem, we can do 2 for loop for easier way, but the idea for one loop is 
great and we should learn how to do it. For example, when we have start and end pointer
represent for 2 swapped node. Then start is for first node, and end will be = len-start+1
 1     2     3    4     5     6     7     8
             |                |
           start             end
           
we have: 
start = start 
end = len-start+1
==> if we set:
start = start ==> go len-start steps, start will be len
end = 1 ==> go len-start steps, end will be (len-start+1) which is the required position for end

==> whenever we find the position of start, we set the end = head, then increase both pointer step
by step until the start reach the end <=> the end reach the corrected position.

Visualization:
 1     2     3    4     5     6     7     8
 |           |                
end         start   


 1     2     3    4     5     6     7     8
       |          |                
      end       start  


 1     2     3    4     5     6     7     8
             |          |                
            end       start  

 1     2     3    4     5     6     7     8
                  |           |                
                 end        start 
                 
 1     2     3    4     5     6     7     8
                        |           |                
                       end         start 
                       
  1     2     3    4     5     6     7     8
                               |           |                
                              end         start 
*/

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int count = 0;
        ListNode *move = head, *start = NULL, *end = NULL;
        while(move != NULL){
            count++;
            if(end != NULL) end = end->next;
            if(count == k) {
                start = move;
                end = head;
            }
            move = move->next;
        }
        swap(start->val, end->val);
        return head;
    }
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int count = 0;
        ListNode *move = head, *start = NULL, *end = NULL;
        while(move != NULL){
            count++;
            if(count == k) {
                start = move;
                end = head;
                move = move->next;
                continue;
            }
            if(end != NULL) end = end->next;
            move = move->next;
        }
        swap(start->val, end->val);
        return head;
    }
};
