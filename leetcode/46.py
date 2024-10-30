class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1:
            return [nums]
        permutations = []

        for i in range(len(nums)):
            curr = nums[i]
            leftover = nums[:i] + nums[i+1:]
            a = self.permute(leftover)
            for permutation in a:
                permutations.append(permutation + [curr])

        return permutations
