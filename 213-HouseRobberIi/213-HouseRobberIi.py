# Last updated: 01/10/2025, 00:13:15
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        def robbing(houses:List[int]) -> int:
            length = len(houses)
            if length == 0:
                return 0
            if length == 1:
                return houses[0]
            prev1 = max(houses[0],houses[1])
            prev2 = houses[0]
            for i in range(2,length):
                current = max(prev1,prev2+houses[i])
                prev2 = prev1
                prev1 = current
            return prev1
        option1 = robbing(nums[:-1])
        option2 = robbing(nums[1:])
        return max(option1,option2)