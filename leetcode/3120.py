class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        count = 0
        visited = []
        letters = 'abcdefghijklmnopqrstuvwxyz'
        for char in word:
            if char.upper() in word and char in letters and char not in visited:
                count += 1
                visited.append(char)
        return count
