class Solution {
    public Node connect(Node root) {
        if(root == null) return root;
        Queue<Node>q = new LinkedList<>();
        q.add(root);
        while(q.size()!=0){
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node top = q.poll();
                if(i == size-1) top.next = null;
                else top.next = q.peek();
                if(top.left != null) q.add(top.left);
                if(top.right != null) q.add(top.right);
            }
        }
        return root;
    }
}

class Solution {
    public Node connect(Node root) {
        Node level = root, move= root;
        while(level !=null && level.left != null){
            move = level;
            while(move != null){
                move.left.next = move.right;
                if(move.next != null) move.right.next = move.next.left;
                move = move.next;
            }
            level = level.left;
        }
        return root;
    }
}
