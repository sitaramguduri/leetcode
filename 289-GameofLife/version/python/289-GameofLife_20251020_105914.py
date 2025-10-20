# Last updated: 20/10/2025, 10:59:14
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # 1-> -1 alive to dead
        #0 -> 2 dead to alive
        rows, cols = len(board), len(board[0])
        def count_live_neighbors(r,c):
            directions = [(-1,-1), (-1,0), (-1,1), (0,-1), (0,1),(1,-1), (1,0), (1,1)]
            live = 0
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0<= nr < rows and 0<= nc< cols:
                    if(abs(board[nr][nc]) == 1):
                        live += 1
            
            return live
        for r in range(rows):
            for c in range(cols):
                live_neighbors = count_live_neighbors(r,c)
                if board[r][c] == 1 and (live_neighbors < 2 or live_neighbors > 3):
                    board[r][c] = -1
                if board[r][c] == 0 and live_neighbors == 3:
                    board[r][c] = 2
        
        for r in range(rows):
            for c in range(cols):
                if board[r][c] > 0:
                    board[r][c] = 1
                else:
                    board[r][c] = 0
        