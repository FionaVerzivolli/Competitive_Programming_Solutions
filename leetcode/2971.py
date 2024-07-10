class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        possible_nums = []
        total = sum(nums)
        # descending list
        nums.sort(reverse=True)
        possible_nums = []
        # for each number, starting with largest
        for i in nums:
            # if it is smaller than the total -> why case 2 fails
            if total - i > i:
                # add
                possible_nums += [i]
            else:
                total -= i
        if len(possible_nums) < 3:
            return -1
        return sum(possible_nums)
