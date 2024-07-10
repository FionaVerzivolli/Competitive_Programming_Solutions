class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        index = -1
        if len(word) <= 1:
            return word
        for i in range(len(word)):
            if word[i] == ch:
                index = i
                break  
        if index == -1:  
            return word
        non_reversed = word[index+1:] 
        reversed_segment = word[:index+1][::-1] 
        return reversed_segment + non_reversed
