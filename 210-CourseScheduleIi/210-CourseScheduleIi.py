# Last updated: 01/10/2025, 00:13:16
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = {i : [] for i in range(numCourses)}
        indegree = [0]* numCourses
        for course, pre in prerequisites:
            adj[pre].append(course)
            indegree[course] += 1
        queue = deque([])
        for i in range(numCourses):
            if indegree[i] == 0:
                queue.append(i)
        order = []

        while queue:
            node = queue.popleft()
            order.append(node)
            for neighbor in adj[node]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)
        
        if len(order) == numCourses:
            return order
        else:
            return []