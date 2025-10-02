# Last updated: 02/10/2025, 00:54:17
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        rows = len(matrix)
        cols = len(matrix[0])
        dp = [[0 for _ in range(cols)] for _ in range(rows)]
        directions = [(1,0),(-1,0),(0,1),(0,-1)]
        def dfs(r,c):
            if dp[r][c]!= 0:
                return dp[r][c]
            max_length = 1
            for dr,dc in directions:
                new_r = r + dr
                new_c = c + dc
                if 0<= new_r <rows and 0 <= new_c < cols and matrix[new_r][new_c] > matrix[r][c]:
                    length = 1 + dfs(new_r,new_c)
                    max_length = max(max_length, length)
            dp[r][c] = max_length
            return max_length
        result = 0
        for i in range(rows):
            for j in range(cols):
                result = max(result, dfs(i,j))
        return result