class Solution:
    def findLatestTime(self, s: str) -> str:
        if s.count("?") == 4:  # base case
            s = "11:59"

        lst = [x for x in s]

        if lst[0] == lst[1] == "?":
            lst[0], lst[1] = "1", "1"

        if lst[0] == "0" and lst[1] == "?":
            lst[1] = "9"

        if lst[0] == "?":
            if int(lst[1]) < 2:
                lst[0] = "1"
            else:
                lst[0] = "0"

        if lst[1] == "?":
            if lst[0] == "1":
                lst[1] = "1"
            else:
                lst[1] = "9"

        if lst[3] == "?":  # case where minutes are missing
            lst[3] = "5"
        if lst[4] == "?":
            lst[4] = "9"

        s = ''.join(lst)
        return s

                
