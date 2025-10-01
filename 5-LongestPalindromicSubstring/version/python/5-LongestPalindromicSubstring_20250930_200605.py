# Last updated: 30/09/2025, 20:06:05
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)

        def expand_from_center(left:int,right:int) -> str:
            while left >= 0 and right < n and s[left] == s[right]:
                left -=1
                right += 1
            return s[left+1:right]
        longest = ""
        for i in range(n):
            odd_palindrome = expand_from_center(i,i) # single digit centers
            even_palindrome = expand_from_center(i,i+1)
            if len(odd_palindrome) > len(longest):
                longest = odd_palindrome
            if len(even_palindrome) > len(longest):
                longest = even_palindrome
        
        return longest