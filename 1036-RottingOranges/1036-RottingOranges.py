# Last updated: 01/10/2025, 00:12:24
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows,cols = len(grid), len(grid[0])

        q = deque()
        fresh = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    q.append((r,c,0))
                elif grid[r][c] == 1:
                    fresh +=1
        
        time = 0
        while q:
            r,c,t = q.popleft()
            time = max(time,t)
            for dr,dc in [(1,0),(-1,0), (0,1), (0,-1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0<=nc < cols and grid[nr][nc] == 1:
                    grid[nr][nc] = 2
                    fresh -= 1
                    q.append((nr,nc,t+1))
        
        return time if fresh == 0 else -1