# Last updated: 02/10/2025, 17:42:37
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        farthest_reach = 0
        for i in range(len(nums)):
            if i > farthest_reach:
                return False
            farthest_reach = max(farthest_reach, i + nums[i])
        
        return farthest_reach >= len(nums) - 1