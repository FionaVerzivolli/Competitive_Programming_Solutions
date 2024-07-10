# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        curr = head
        i = 0
        positions = []

        while(curr and curr.next and curr.next.next):
            a = curr.val
            b = curr.next.val
            c = curr.next.next.val
            if (a < b and b > c) or (a > b and b < c):
                positions.append(i + 1)
            i += 1
            curr = curr.next

        if len(positions) < 2:
            return [-1, -1]

        min_dist = float('inf')
        for j in range(1, len(positions)):
            min_dist = min(min_dist, positions[j] - positions[j - 1])
        
        max_dist = positions[-1] - positions[0]
    
        
        return [min_dist, max_dist]
