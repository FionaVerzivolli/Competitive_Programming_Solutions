class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        indices = {}
        for i in range(len(s)):
            if s[i] not in indices:
                indices[s[i]] = [i]
            else:
                indices[s[i]].append(i)        
        start_idx = []
        last_idx = []
        for index in indices.values():
            start_idx.append(index[0])
            last_idx.append(index[-1])  
        intervals = []
        current_start = start_idx[0]
        current_end = last_idx[0]
        for i in range(1, len(start_idx)):
            if start_idx[i] > current_end:
                intervals.append(current_end - current_start + 1)
                current_start = start_idx[i]
                current_end = last_idx[i]
            else:
                current_end = max(current_end, last_idx[i])
        intervals.append(current_end - current_start + 1)
        return intervals
