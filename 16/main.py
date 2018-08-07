'''
Task:
You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
You should be as efficient with time and space as possible.

Solution:
Time: insert - O(1), get_last - O(1)
Memory: O(n)
'''

class Log:
    def __init__(self, n):
        self.entries = [None] * n
        self.length = n
        self.index = 0

    def record(self, text):
        self.entries[self.index % self.length] = text
        self.index = (self.index + 1) % self.length

    def get_last(self, i):
        return self.entries[(self.index + self.length - i) % self.length]

n = 5
log = Log(n)
entries = [i for i in range(1, 2 * n)]

for text in entries:
    log.record(text)
    print(log.entries, [log.get_last(i) for i in range(1, n + 1)])