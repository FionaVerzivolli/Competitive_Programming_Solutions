class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        
        for num in nums:
            if num not in freq:
                freq[num] = 1
            else:
                freq[num] += 1
        
        sorted_items = sorted(freq.items(), key=lambda item: item[1], reverse=True)
        
        array = []
        for i in range(k):
            array.append(sorted_items[i][0]) 
        
        return array
