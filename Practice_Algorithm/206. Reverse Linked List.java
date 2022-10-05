class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        while(head != null){
            ListNode after = head.next;
            head.next = pre;
            pre = head;
            head = after;
        }
        return pre;
    }
}
