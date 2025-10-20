# Last updated: 20/10/2025, 10:25:02
class CustomStack:

    def __init__(self, maxSize: int):
        self.stack = []
        self.inc = [0]* maxSize
        self.maxSize = maxSize

    def push(self, x: int) -> None:
        if len(self.stack) < self.maxSize:
            self.stack.append(x)

    def pop(self) -> int:
        if not self.stack:
            return -1
        idx = len(self.stack) - 1
        val = self.stack.pop() + self.inc[idx]
        if idx > 0:
            self.inc[idx - 1] += self.inc[idx]
        self.inc[idx] = 0
        return val

    def increment(self, k: int, val: int) -> None:
        limit = min(k, len(self.stack))
        if limit > 0:
            self.inc[limit - 1] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)