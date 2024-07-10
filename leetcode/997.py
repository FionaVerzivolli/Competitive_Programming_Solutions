class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if n == 1:
            return 1

        trust_count = [0] * (n + 1)
        trusting_count = [0] * (n + 1)

        for t in trust:
            trust_count[t[1]] += 1  
            trusting_count[t[0]] += 1  

        for person in range(1, n + 1):
            if trust_count[person] == n - 1 and trusting_count[person] == 0:
                return person

        return -1
