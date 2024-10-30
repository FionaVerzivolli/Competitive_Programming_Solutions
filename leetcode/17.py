class Solution:
    def __init__(self):
        self.map = {"2": ["a", "b", "c"], "3": ["d", "e", "f"], "4": ["g", "h", "i"], 
        "5":["j", "k", "l"], "6": ["m", "n", "o"], "7": ["p", "q", "r", "s"], 
        "8": ["t", "u", "v"], "9": ["w", "x", "y", "z"]}

    def letterCombinations(self, digits: str) -> List[str]:
        permutations = []
        for i in range(0, len(digits)):
            if permutations == []:
                permutations += self.map[digits[i]] # add initial values
            else:
                x = []
                b = self.map[digits[i]] # ["a", "b, "c"]
                for letter in b:
                    for permutation in permutations:
                        new = permutation
                        new += letter
                        x.append(new)
                permutations = x
        return permutations
