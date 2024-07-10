class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0
        x = len(nums)

        for i in range(x - 1, 0, -1):
            if nums[i] == nums[i - 1]:
                count += 1
                if count >= 2:
                    nums.pop(i)
                    count += 1
                    x -= 1
            else:
                count = 0

        return len(nums)
