class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        b = len(part)
        end = len(s)

        listify = []

        if end < b:
            return s

        for letter in s:
            listify.append(letter)

        start = 0

        while start < len(listify):
            if listify[start] == part[0]:
                if "".join(listify[start: start + b]) == part:
                    for i in range(0, b):
                        listify.pop(start)
                    start = 0
                else:
                    start+=1
            else:
                start+=1
                
    
        return "".join(listify)
        
