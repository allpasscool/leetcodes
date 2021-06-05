/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null)
            return null;

        Node cur = head;

        // duplicate node
        while (cur != null) {
            Node next = cur.next;
            cur.next = new Node(cur.val);
            cur.next.random = cur.random;
            cur.next.next = next;

            cur = cur.next.next;
        }

        Node newHead = head.next;
        cur = head;

        // update random
        while (cur != null) {
            if (cur.next.random != null) {
                cur.next.random = cur.random.next;
            }
            cur = cur.next.next;

        }

        cur = head;
        Node newCur = newHead;

        while (cur.next.next != null) {
            Node next = cur.next.next;
            cur.next = next;
            newCur.next = next.next;

            cur = cur.next;
            newCur = newCur.next;
        }

        cur.next = cur.next.next;

        return newHead;
    }
}

// Runtime: 1 ms, faster than 10.02% of Java online submissions for Copy List
// with Random Pointer.
// Memory Usage: 42.3 MB, less than 5.60% of Java online submissions for Copy
// List with Random Pointer.
// time complexity: O(n)
// space complexity: O(1)