# Last updated: 01/10/2025, 00:12:41
class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        count = 0

        def isPalindrome(left:int,right:int) ->int:
            current_count = 0
            while left>=0 and right<n and s[left] == s[right]:
                current_count += 1
                left -= 1
                right +=1
            return current_count
        for i in range(n):
            count += isPalindrome(i,i)
            count += isPalindrome(i,i+1)
        return count
        