# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        lst = []
        curr = head
        while curr is not None:
            lst += [curr.val]
            curr = curr.next
    
        for i in range(0, int(len(lst)/2)):
            if lst[i] != lst[len(lst) - i - 1]:
                return False

        return True    
