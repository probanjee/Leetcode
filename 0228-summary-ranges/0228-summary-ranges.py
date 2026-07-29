from typing import List

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []
            
        result = []
        i = 0
        while i < len(nums):
            start = nums[i]
            j = i
            # Expand the range as long as elements are consecutive
            while j + 1 < len(nums) and nums[j + 1] == nums[j] + 1:
                j += 1
            
            # Format the range string
            if nums[j] == start:
                result.append(str(start))
            else:
                result.append(f"{start}->{nums[j]}")
            
            # Move to the next potential start of a range
            i = j + 1
        return result