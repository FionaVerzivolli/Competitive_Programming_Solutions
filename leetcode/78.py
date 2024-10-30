class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        powerSet = [[]]
        if len(nums) == 1:
            powerSet.append(nums)
            return powerSet
        else:
            prev = self.subsets(nums[:-1])
            b = prev.copy()
            for sublist in b:
                prev.append(sublist + [nums[-1]])
            return prev
            # take prev result and make a copy of the subset
            # add the num to every sublist
        
