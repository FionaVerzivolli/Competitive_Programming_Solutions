class Solution:
    def validStrings(self, n: int) -> List[str]:
        if n == 1:
            return ["0", "1"]
        
        valid_strings = ["0", "1"]
        
        for i in range(2, n + 1):
            new_valid_strings = []
            for s in valid_strings:
                new_valid_strings.append(s + '0')
                new_valid_strings.append(s + '1')
            valid_strings = new_valid_strings
        
        return [x for x in valid_strings if '00' not in x]
