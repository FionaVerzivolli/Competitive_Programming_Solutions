class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        greatest = max(candies) # most candies kid has
        result = []
        for i in range(0, len(candies)):
            result.append(greatest <= (candies[i] + extraCandies))
        
        return result
