class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        visited = []
        curr = head
        
        while curr:
            if curr in visited:
                return True
            visited.append(curr)
            curr = curr.next
        
        return False
