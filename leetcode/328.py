# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if(head == None) or head.next == None:
            return head
        even = ListNode(0)
        odd = ListNode(0)
        dummy_even = even
        dummy_odd = odd
        index = 0

        while head:
            if(index % 2 == 1):
                dummy_even.next = head
                dummy_even = dummy_even.next
            else:
                dummy_odd.next = head
                dummy_odd = dummy_odd.next
            head = head.next
            index+=1

        dummy_even.next = None
        dummy_odd.next = even.next

        return odd.next


        
