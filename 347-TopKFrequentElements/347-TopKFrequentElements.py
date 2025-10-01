# Last updated: 01/10/2025, 00:12:54
from collections import Counter
import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_map = Counter(nums)
        top_k_pairs = heapq.nlargest(k,freq_map.items(), key = lambda x:x[1])
        result = [num for num,freq in top_k_pairs]
        return result
        