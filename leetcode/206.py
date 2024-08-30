class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        nodes = []
        curr = head
        
        while curr:
            nodes.append(curr)
            curr = curr.next
            
        if not nodes:
            return None
        
        new_head = nodes[-1]
        
        for i in range(len(nodes) - 1, 0, -1):
            nodes[i].next = nodes[i - 1]
        
        nodes[0].next = None
        
        return new_head
