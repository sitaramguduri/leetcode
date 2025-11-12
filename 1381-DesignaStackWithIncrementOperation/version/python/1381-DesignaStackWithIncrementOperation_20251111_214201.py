# Last updated: 11/11/2025, 21:42:01
class CustomStack:

    def __init__(self, maxSize: int):
        self.stack = []
        self.inc = [0]*maxSize
        self.maxSize = maxSize

    def push(self, x: int) -> None:
        if len(self.stack) < self.maxSize:
            self.stack.append(x)
    def pop(self) -> int:
        if not self.stack:
            return -1
        idx = len(self.stack) - 1
        inc_val = self.inc[idx]
        val = self.stack[idx] + inc_val
        self.stack.pop()
        if idx > 0:
            self.inc[idx-1] += inc_val
        self.inc[idx] = 0
        return val
    def increment(self, k: int, val: int) -> None:
        if self.stack:
            limit = min(k, len(self.stack)) - 1
            self.inc[limit] += val
        

    
        


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)