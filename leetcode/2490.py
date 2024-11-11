class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        first = sentence[0]
        l = sentence.split()

        for i in range(0, len(l) - 1):
            if l[i][-1] != l[i+1][0]:
                return False

        return first == sentence[-1]

        
