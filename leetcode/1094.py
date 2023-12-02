from ast import List
from collections import Counter


class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        c = Counter()
        for n, f, t in trips:
            c[f] += n
            c[t] -= n

        s = 0
        for i in sorted(c):
            s += c[i]
            if s > capacity:
                return False
        return True


# 差分数组
# https://leetcode.cn/problems/car-pooling/description/
