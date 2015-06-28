class Solution:
    def twoSum(self, num, target):
        cache = {}
        for e, v in enumerate(num):
            if v in cache:
                return [cache[v] + 1, e + 1]
            else:
                cache[target - v] = e
