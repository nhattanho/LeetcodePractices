class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode s = head, f = head;
        while(f.next != null && f.next.next != null){
            s = s.next;
            f = f.next.next;
        }
        return f.next == null?s:s.next;
    }
}
