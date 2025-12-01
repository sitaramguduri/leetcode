# Last updated: 30/11/2025, 23:22:44
1class Logger:
2
3    def __init__(self):
4        self.message_timestamps = {}
5
6    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
7        if message not in self.message_timestamps:
8            self.message_timestamps[message] = timestamp + 10
9            return True
10        if timestamp < self.message_timestamps[message]:
11            return False
12        self.message_timestamps[message] = timestamp + 10
13        return True
14
15
16# Your Logger object will be instantiated and called as such:
17# obj = Logger()
18# param_1 = obj.shouldPrintMessage(timestamp,message)