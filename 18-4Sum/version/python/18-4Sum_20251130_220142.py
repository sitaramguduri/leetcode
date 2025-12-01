# Last updated: 30/11/2025, 22:01:42
1class MyCircularQueue:
2
3    def __init__(self, k: int):
4        self.queue = [0]*k
5        self.front = 0
6        self.rear = 0
7        self.size = k
8        self.count = 0
9
10    def enQueue(self, value: int) -> bool:
11        if self.isFull():
12            return False
13        self.queue[self.rear] = value
14        self.rear = (self.rear + 1)%self.size
15        self.count += 1
16        return True
17
18    def deQueue(self) -> bool:
19        if self.isEmpty():
20            return False
21        self.front = (self.front + 1)%self.size
22        self.count -= 1
23        return True
24
25    def Front(self) -> int:
26        if self.isEmpty():
27            return -1
28        return self.queue[self.front]
29
30    def Rear(self) -> int:
31        if self.isEmpty():
32            return -1
33        return self.queue[(self.rear - 1 + self.size) % self.size]
34    def isEmpty(self) -> bool:
35        return self.count == 0
36
37    def isFull(self) -> bool:
38        return self.count == self.size
39        
40
41
42# Your MyCircularQueue object will be instantiated and called as such:
43# obj = MyCircularQueue(k)
44# param_1 = obj.enQueue(value)
45# param_2 = obj.deQueue()
46# param_3 = obj.Front()
47# param_4 = obj.Rear()
48# param_5 = obj.isEmpty()
49# param_6 = obj.isFull()