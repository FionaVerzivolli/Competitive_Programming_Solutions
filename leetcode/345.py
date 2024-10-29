class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = "aeiouAEIOU"
        size = len(s)
        vows = []
        join = ""
        for i in range(0, size):
            if s[i] in vowels:
                vows.append(s[i])
        for i in range(0, size):
            if s[i] in vowels:
                join+=vows[-1]
                vows.pop()
            else:
                join+=s[i]
        return join

        
