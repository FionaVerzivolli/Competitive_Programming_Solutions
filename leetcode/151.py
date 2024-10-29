class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        string = ""
        size = len(words)
        for i in range(0, size//2):
            tmp = words[i]
            words[i] = words[size - 1 - i]
            words[size - 1 - i] = tmp

        return " ".join(words)

        
