# Last updated: 01/10/2025, 00:12:42
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(x,y):
            rootX = find(x)
            rootY = find(y)
            if rootX == rootY:
                return False
            if rank[rootX] > rank[rootY]:
                parent[rootY] = rootX
            elif rank[rootX] < rank[rootY]:
                parent[rootX] = rootY
            else:
                parent[rootY] = rootX
                rank[rootX] += 1
            return True
        
        n = len(edges)
        parent = [i for i in range(n+1)]
        rank = [0] * (n+1)
        for u, v in edges:
            if not union(u,v):
                return [u,v]
        