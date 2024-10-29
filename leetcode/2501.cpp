class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        a = nums.copy()
        a = set(a)
        longest = -1
        count = -1
        last = 0
        for i in range(0, len(nums)):
            if(nums[i]**2 in a):
                count = 1
                print(str(nums[i]) + ',' + str(count))

                last = nums[i]**2
                while(last != 0):
                    print(str(last) + ',' + str(count))
                    longest = max(longest, count)
                    if(last in a):
                        count+=1
                        last = last**2
                    else:
                        count = -1
                        break
        return longest


        
