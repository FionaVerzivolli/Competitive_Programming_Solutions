# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        a = guess(n)
        if a == 0:
            return n
        else:
            high = n
            low = 0
            
            while low <= high:
                mid = (high + low)//2
                if guess(mid) == 1:
                    low = mid + 1
                if guess(mid) == -1:
                    high = mid - 1
                if guess(mid) == 0:
                    return mid
            return n
        
