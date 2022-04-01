/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        
        if (head == null) {
            return head;
        }
        
        ListNode temp = head;
        ListNode tail = null;
        ListNode prev = null;
        int length = 0;
        while (temp != null) {
            length++;
            if (temp.next == null) {
                tail = temp;
            }
            temp = temp.next;
        }
        
        int i = length - (k % length);
        
        if (length == 1 || length == i) {
            return head;
        }
        
        temp = head;
        while (i > 0) {          
            prev = temp;
            temp = temp.next;            
            i--;
        }
        temp = prev.next;
        prev.next = null;
        tail.next = head;

        return temp;
    }
}