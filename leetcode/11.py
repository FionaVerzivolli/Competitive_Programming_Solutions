class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        # water is contained by the shorter of the two walls
        # the area is smallest length * the distance between shortest and 
        # longest length
        # must be O(n) 
        if len(height) == 1: # only one wall
            return 0
        elif len(height) == 2: # only two walls
            return min(height)
        else:
            i = 0
            j = len(height) - 1
            max_area = 0
            while i < j:
                area = min(height[i], height[j]) * abs(j - i)
                max_area = max(max_area, area)
                if height[i] < height[j]:
                    i += 1
                else:
                    j -= 1
                    
            return max_area
