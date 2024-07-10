#Time Complexity: O(n)
#Space Complexity: O(1)
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        c1=c2=0
        temp1,temp2=headA,headB
        while temp1 or temp2:
            if temp1:
                c1+=1
                temp1=temp1.next
            if temp2:
                c2+=1
                temp2=temp2.next
        c=c1-c2
        if c<0:
            while c!=0:
                headB=headB.next
                c+=1
        else:
            while c!=0:
                headA=headA.next
                c-=1
        while headA:
            if headA==headB:
                return headA
            headA=headA.next
            headB=headB.next
        return headA
