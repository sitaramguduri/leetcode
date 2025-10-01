# Last updated: 01/10/2025, 00:12:21
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:

        def dfs(node, max_so_far):
            if not node:
                return 0
            
            good = 1 if node.val >= max_so_far else 0

            new_max = max(max_so_far, node.val)
            left_good = dfs(node.left, new_max)
            right_good = dfs(node.right, new_max)

            return good + left_good+ right_good
        
        return dfs(root, root.val)
        