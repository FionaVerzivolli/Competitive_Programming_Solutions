class Solution:
    def isValid(self, s: str) -> bool:
        # similar to stacks
        # add 1 to a placeholder value, 
        # need to check if ) happens before (
        # make a new list, if ( is in our values, add itto the list, if there 
        # is a ), then pop the value. if there is no previous ) then it should
        # return an error 
        stack = []
        brackets = {")": "(", "}": "{", "]": "["}
        
        for char in s:
            if char in brackets.values():  
                stack.append(char)
            elif char in brackets: 
                if not stack or stack[-1] != brackets[char]:
                    return False
                stack.pop()
            else:
                return False
        
        return not stack  
