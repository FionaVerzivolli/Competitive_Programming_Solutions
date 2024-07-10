# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head # initialize curr
        while curr.next: 
            curr = first = curr.next # first value after 0 is our first node
            while curr.next.val != 0: # need to check nodes between
                first.val += curr.next.val # add
                curr = curr.next # switch nodes
            
            curr = curr.next
            first.next = curr.next # repeat cycle
        
        return head.next

        
