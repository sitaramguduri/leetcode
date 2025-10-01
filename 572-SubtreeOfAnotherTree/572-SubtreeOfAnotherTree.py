# Last updated: 01/10/2025, 00:12:45
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def same(a: Optional[TreeNode], b:Optional[TreeNode]) -> bool:
            if not a and not b:
                return True
            
            if not a or not b  or a.val!=b.val:
                return False
            
            return same(a.left, b.left) and same(a.right, b.right)
        
        if not subRoot:
            return True
        
        if not root:
            return False
        
        if same(root, subRoot):
            return True
        
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
        

        