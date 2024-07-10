class Solution:
    def countVowelSubstrings(self, word: str) -> int:
        size = len(word)
        amount = 0
        
        vowels = {'a', 'e', 'i', 'o', 'u'}
        
        for i in range(size):
            for j in range(i + 4, size):  
                substring = word[i:j+1]
                if all(v in substring for v in vowels) and all(v in vowels for v in substring):
                    amount += 1
        
        return amount
