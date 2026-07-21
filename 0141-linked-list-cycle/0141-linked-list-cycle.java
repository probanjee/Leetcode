class Solution {
    public boolean hasCycle(ListNode head) {

        HashSet<ListNode> visited = new HashSet<>();

        while(head != null){

            if(visited.contains(head)){
                return true;
            }

            visited.add(head);
            head = head.next;
        }

        return false;
    }
}