# Last updated: 01/10/2025, 22:11:13
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        total_sum = sum(nums)
        if total_sum < abs(target) or (target + total_sum ) %2 != 0:
            return 0
        subset_sum = (target + total_sum)//2
        dp = [0]*(subset_sum + 1)
        dp[0] = 1
        for num in nums:
            for x in range(subset_sum, num-1, -1):
                dp[x] += dp[x-num]
            
        return dp[subset_sum]
        