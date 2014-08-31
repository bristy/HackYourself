class LRUCache:

    # @param capacity, an integer
    def __init__(self, capacity):
        from collections import deque

        self.capacity = capacity
        self.cache = {}
        self.queue = deque()

    # @return an integer
    def get(self, key):
        if key in self.cache:
            #update queue
            self.queue.remove(key)
            self.queue.append(key)
            return self.cache[key]
        else:
            return -1

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):

        if key in self.cache:
            self.queue.remove(key)
        while len(self.queue) >= self.capacity:
            k = self.queue.popleft()
            print "invaludating " + str(k) + " : "  + str(self.cache[k])
            del(self.cache[k])


        self.cache[key] = value
        self.queue.append(key)


lru = LRUCache(3)
lru.set(1, 2)
lru.set(3, 3)
lru.set(2, 2)
lru.get(1)
lru.set(4, 2)
