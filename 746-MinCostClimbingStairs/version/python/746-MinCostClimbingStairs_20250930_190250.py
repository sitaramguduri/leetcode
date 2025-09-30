# Last updated: 30/09/2025, 19:02:50
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        if n == 1:
            return cost[0]
        if n == 2:
            return min(cost[1],cost[0])
        prev1 = cost[0]
        prev2 = cost[1]
        for i in range(2,n):
            current = cost[i] + min(prev1,prev2)
            prev1 = prev2
            prev2 = current
        return min(prev1,prev2)