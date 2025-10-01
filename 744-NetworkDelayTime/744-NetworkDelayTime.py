# Last updated: 01/10/2025, 00:12:34
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = defaultdict(list)
        for u, v, w in times:
            graph[u].append((v,w))
        heap = [(0,k)]
        dist = {}
        
        while heap:
            time, node = heapq.heappop(heap)
            if node in dist:
                continue
            dist[node] = time
            for neighbor, weight in graph[node]:
                if neighbor not in dist:
                    heapq.heappush(heap,(time + weight,neighbor))
        if len(dist) != n:
            return -1
        return max(dist.values())