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
/*
 if(!head || !head->next) return head;
        ListNode *prev=NULL, *next=head->next, *curr=head;
        while(curr) {
            curr->next = prev;
            prev = curr;
            curr = next;
            if(next)
            next = next->next;
        }
        return prev;
*/
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head==null) return null;
        ListNode prev = null, next=head.next, curr=head;
        while(curr!=null) {
            curr.next = prev;
            prev=curr;
            curr=next;
            if(next!=null)
            next=curr.next;
        }
        return prev;
    }
}