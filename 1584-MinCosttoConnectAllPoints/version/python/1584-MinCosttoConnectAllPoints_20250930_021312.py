# Last updated: 30/09/2025, 02:13:12
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        visited = set()
        visited.add(0)
        minHeap = []
        for i in range(1,n):
            x1,y1 = points[0]
            x2,y2 = points[i]
            cost = abs(x1-x2) + abs(y1-y2)
            heapq.heappush(minHeap,(cost,i))
        total_cost = 0
        while len(visited) < n:
            cost, next_point = heapq.heappop(minHeap)

            if next_point in visited:
                continue
            visited.add(next_point)
            total_cost += cost
            for i in range(n):
                if i not in visited:
                    x1, y1 = points[next_point]
                    x2,y2 = points[i]
                    new_cost = abs(x1-x2) + abs(y1-y2)
                    heapq.heappush(minHeap,(new_cost,i))

        return total_cost
        