class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode s = head, f = head, pre = head;
        for(int i = 0; i < n; i++){
            f = f.next;
        }
        while(f!=null){
            pre = s;
            s = s.next;
            f = f.next;
        }
        pre.next = s.next;
        return pre==s?head.next:head;
    }
}
