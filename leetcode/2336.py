import heapq


class SmallestInfiniteSet:
    def __init__(self):
        self.s = 1
        self.h = []

    def popSmallest(self) -> int:
        if not self.h:
            self.s += 1
            return self.s - 1
        return heapq.heappop(self.h)

    def addBack(self, num: int) -> None:
        # h里面的数不能重复
        if num >= self.s or num in self.h:
            return
        heapq.heappush(self.h, num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)

# 最小堆
# https://leetcode.cn/problems/smallest-number-in-infinite-set/ 无限集中的最小数字
