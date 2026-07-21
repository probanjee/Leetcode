
class Solution {
    public Node connect(Node root) {
        if (root == null) return root;

        Node leftMost = root;

        // Traverse level by level
        while (leftMost.left != null) {
            Node curr = leftMost;
            while (curr != null) {
                // Connect left -> right
                curr.left.next = curr.right;

                // Connect right -> next's left (if available)
                if (curr.next != null) {
                    curr.right.next = curr.next.left;
                }

                curr = curr.next; // Move to next node in the level
            }
            leftMost = leftMost.left; // Go to next level
        }
        return root;
    }
}