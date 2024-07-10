class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        num_set = set(nums)
        max_number = max(nums)
        
        for num in range(1, max_number + 1):
            if num not in num_set:
                return num
        if max_number < 0:
            return 1
        return max_number + 1
