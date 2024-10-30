class Solution:
    def __init__(self):
        self.memo = ["1"] 

    def countAndSay(self, n: int) -> str:

        if n <= len(self.memo):
            return self.memo[n - 1]
        
        previous_term = self.countAndSay(n - 1)
        result = ""
        count = 1
        
        for i in range(1, len(previous_term)):
            if previous_term[i] == previous_term[i - 1]:
                count += 1
            else:
                result += str(count) + previous_term[i - 1]
                count = 1  
        
        result += str(count) + previous_term[-1]

        self.memo.append(result)
        return result

