class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        def gcd(a, b):
            while b != 0:
                a, b = b, a % b
            return a
        
        dummy = head
        curr = head
        
        while curr and curr.next:
            gcd_val = gcd(curr.val, curr.next.val)
            
            tmp1 = curr.next
            curr.next = ListNode(gcd_val, tmp1)
            
            curr = tmp1
        
        return dummy
