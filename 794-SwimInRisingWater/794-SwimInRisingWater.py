# Last updated: 01/10/2025, 00:12:32
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        minHeap = [(grid[0][0],0,0)]
        visited = set()
        visited.add((0,0))
        result = 0
        direction = [(1,0),(-1,0),(0,1),(0,-1)]

        while minHeap:
            elevation,r,c = heapq.heappop(minHeap)
            result = max(result,elevation)
            if r == n-1 and c == n-1:
                return result
            for dr,dc in direction:
                nr,nc = r + dr, c +dc
                if 0<= nr < n and 0 <= nc < n and (nr,nc) not in visited:
                    visited.add((nr,nc))
                    heapq.heappush(minHeap,(grid[nr][nc],nr,nc))
        return -1