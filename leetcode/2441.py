class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        nums = set(nums)
        maximum = -1
        for num in nums:
            if (0 - num) in nums and abs(num) > maximum:
                maximum = abs(num)
        return maximum
