class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        ns = len(needle)
        hs = len(haystack)
        
        if ns > hs:
            return -1
        
        if haystack == needle:
            return 0
        
        for i in range(0, hs - ns + 1):
            if haystack[i:i + ns] == needle:
                return i
            
        return -1
